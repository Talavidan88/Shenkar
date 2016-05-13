// ***********************************************************************
// Assembly         : CSharp End Proj WS API
// Author           : Tal
// Created          : 05-12-2016
//
// Last Modified By : Tal
// Last Modified On : 05-12-2016
// ***********************************************************************
// <copyright file="FBUser.cs" company="">
//     Copyright ©  2016
// </copyright>
// <summary></summary>
// ***********************************************************************
using Facebook;
using Newtonsoft.Json;
using Newtonsoft.Json.Linq;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Text.RegularExpressions;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Runtime.Serialization;
using CSharp_End_Proj_WS_API.WeatherService;

namespace CSharp_End_Proj_WS_API
{
    /// <summary>
    /// Class MyFaceBook.
    /// </summary>
    /// <seealso cref="CSharp_End_Proj_WS_API.IDataService" />
    public class MyFaceBook : IDataService
    {
        /// <summary>
        /// /thread safe singleton object.
        /// </summary>
        private static readonly MyFaceBook _instance = new MyFaceBook(); //thread safe singleton object.

        /// <summary>
        /// The likes
        /// </summary>
        private Dictionary<string, FBUserLike> likes = new Dictionary<string, FBUserLike>();
        /// <summary>
        /// The events
        /// </summary>
        private Dictionary<string, FBUserEvent> events = new Dictionary<string, FBUserEvent>();
        /// <summary>
        /// The details
        /// </summary>
        private FBUserDetails details;
        /// <summary>
        /// The applications identifier
        /// </summary>
        private const string AppId = "983596705057042";
        /// <summary>
        /// The applications secret
        /// </summary>
        private const string secret = "ec3854665f7fc2caf97c596a5f732bf4";
        /// <summary>
        /// The permmisions wanted by this app
        /// </summary>
        private const string Perm = "publish_actions,email,user_birthday,user_friends,user_likes,user_photos,user_posts,user_events";
        /// <summary>
        /// The Webbrowser
        /// </summary>
        private static WebBrowser wb;
        /// <summary>
        /// is authenticated?
        /// </summary>
        private bool isAuthenticated = false;
        /// <summary>
        /// The form
        /// </summary>
        private static Form form;
        /// <summary>
        /// Facebook API Client.
        /// </summary>
        private static FacebookClient fb;
        /// <summary>
        /// The delegate exeption
        /// </summary>
        private static Exception delegateExeption;

        /// <summary>
        /// Gets the instance.
        /// </summary>
        /// <value>The instance.</value>
        public static MyFaceBook Instance
        {
            get
            {
                return _instance;
            }
        }
        /// <summary>
        /// Gets my likes.
        /// </summary>
        /// <value>My likes.</value>
        public Dictionary<string, FBUserLike> MyLikes
        {
            get
            {
                return likes;
            }
        }
        /// <summary>
        /// Gets my events.
        /// </summary>
        /// <value>My events.</value>
        public Dictionary<string, FBUserEvent> MyEvents
        {
            get
            {
                return events;
            }

        }
        /// <summary>
        /// Gets the details.
        /// </summary>
        /// <value>The details.</value>
        /// <exception cref="System.Exception"></exception>
        public FBUserDetails Details
        {
            get
            {
                return details;
            }

            private set
            {
                if (value == null)
                    throw new Exception();
                details = value;
            }
        }

        /// <summary>
        /// Prevents a default instance of the <see cref="MyFaceBook"/> class from being created.
        /// </summary>
        private MyFaceBook()
        {

        }

        /// <summary>
        /// Gets the data.
        /// </summary>
        /// <exception cref="FBNoData">No Data! Did You Close The Browser Without Authenticating?</exception>
        public void getData()
        {
            if (fb != null)
            {
                isAuthenticated = true;
                parseLikes(JObject.Parse(fb.Get("me?fields=likes{name,created_time,about}").ToString()));
                parseEvents(JObject.Parse(fb.Get("me?fields=events{start_time,name,description}").ToString()));
                ParseUser(JObject.Parse(fb.Get("me?fields=birthday,name,email").ToString()));
            }
            else
                throw new FBNoData("No Data! Did You Close The Browser Without Authenticating?");

        }
        /// <summary>
        /// Authenticates this User with Facebook.
        /// </summary>
        /// <exception cref="FBAlreadyAuthenticated">You can't authenticate twice!</exception>
        public void Authenticate()
        {
            if (isAuthenticated == true)
                throw new FBAlreadyAuthenticated("You can't authenticate twice!");
            browserThread();
            if (delegateExeption != null)
                throw delegateExeption;
        }
        /// <summary>
        /// Opens the webbrowser.
        /// </summary>
        private static void browserThread()
        {
            string url = string.Format(@"https://www.facebook.com/dialog/oauth?client_id={0}&scope={1}&redirect_uri=http://www.facebook.com/connect/login_success.html&response_type=token"
            , AppId, Perm);

            wb = new WebBrowser();
            wb.Dock = DockStyle.Fill;
            wb.Name = "webBrowser";
            wb.ScrollBarsEnabled = false;
            wb.TabIndex = 0;
            wb.Navigated += WebBrowserNavigated;

            form = new Form();
            form.WindowState = FormWindowState.Normal;
            form.Width = 1000;
            form.Height = 600;
            form.Controls.Add(wb);
            form.Name = "Browser";
            wb.Navigate(url);
            Application.Run(form);
            
        }
        /// <summary>
        /// WebBrowsers navigated delegate.
        /// </summary>
        /// <param name="sender">The sender.</param>
        /// <param name="e">The <see cref="WebBrowserNavigatedEventArgs"/> instance containing the event data.</param>
        private static void WebBrowserNavigated(object sender, WebBrowserNavigatedEventArgs e)
        {
            // get token
            var url = e.Url.Fragment;
            if (url.Contains("access_token") && url.Contains("#"))
            {
                string AccessToken;
                url = (new Regex("#")).Replace(url, "?", 1);
                AccessToken = System.Web.HttpUtility.ParseQueryString(url).Get("access_token");
                wb.Dispose();
                form.Dispose();

                fb = new FacebookClient(AccessToken);
                Instance.getData();
                Application.ExitThread();
            }
            else if (e.Url.ToString().Contains("user_denied")&& e.Url.ToString().Contains("#"))
            {
                wb.Dispose();
                form.Dispose();
                delegateExeption = new FBUserDeclined();
            }
        }

        /// <summary>
        /// Parses the user.
        /// </summary>
        /// <param name="userJson">The user json.</param>
        private void ParseUser(JObject userJson)
        {
            Details = new FBUserDetails(userJson["name"].ToString(), userJson["birthday"].ToString(), userJson["email"].ToString(), userJson["id"].ToString());
        }

        /// <summary>
        /// Parses the events.
        /// </summary>
        /// <param name="eventsJson">The events json.</param>
        private void parseEvents(JObject eventsJson)
        {
            var obj = from x in eventsJson["events"]["data"]
                      select new
                      {
                          name = (string)x["name"],
                          des = (string)x["description"],
                          st = (string)x["start_time"]
                      };
            foreach (var i in obj)
            {
                events.Add(i.name, new FBUserEvent(i.name, i.des, i.st));
            }
        }

        /// <summary>
        /// Parses the likes.
        /// </summary>
        /// <param name="likesJson">The likes json.</param>
        private void parseLikes(JObject likesJson)
        {
            var obj = from x in likesJson["likes"]["data"]
                      select new
                      {
                          name = (string)x["name"],
                          id = (string)x["id"],
                          liked_time = (string)x["created_time"],
                          about = (string)x["about"]
                      };
            foreach (var i in obj)
            {
                likes.Add(i.name, new FBUserLike(i.name, i.id, i.liked_time, i.about));
            }
        }

        /// <summary>
        /// Posts the specified MSG.
        /// </summary>
        /// <param name="msg">The MSG.</param>
        /// <returns>System.String. Post ID</returns>
        /// <exception cref="FBUserDuplicatePost"></exception>
        /// <exception cref="FBUserDeclined">User Did Not Give Post Permissions</exception>
        public string Post(string msg)
        {
            try
            {
                dynamic res = fb.Post("me/feed", new { message = msg });
                return res.id;
            }
            catch (Exception e)
            {
                if (e.Message.Contains("506"))
                    throw new FBUserDuplicatePost();
                throw new FBUserDeclined("User Did Not Give Post Permissions");
            }
        }
        /// <summary>
        /// Deletes the specified identifier.
        /// </summary>
        /// <param name="id">The identifier.</param>
        public void Delete(string id)
        {
            try
            {
                dynamic res = fb.Delete(id);

            }catch(Exception e)
            {
                throw e;
            }

        }
        /// <summary>
        /// Returns a <see cref="System.String" /> that represents this instance.
        /// </summary>
        /// <returns>A <see cref="System.String" /> that represents this instance.</returns>
        /// <exception cref="FBNoData">No Data! Did You Close The Browser Without Authenticating?</exception>
        public override string ToString()
        {
            string ret;
            if (Details != null)
                ret = Details.ToString();
            else
                throw new FBNoData("No Data! Did You Close The Browser Without Authenticating?");
            foreach (KeyValuePair<string, FBUserEvent> ent in MyEvents)
            {
                ret += ent.Value.ToString();
            }
            foreach (KeyValuePair<string, FBUserLike> ent in MyLikes)
            {
                ret += ent.Value.ToString();
            }

            return ret;


        }

        /// <summary>
        /// Gets the weather data.
        /// </summary>
        /// <param name="location">The location.</param>
        /// <returns>WeatherData.</returns>
        /// <exception cref="System.NotImplementedException">Facebook doesn't do weather...</exception>
        public OpenWeatherMap.Root GetWeatherData(Location location)
        {
            throw new NotImplementedException("Facebook doesn't do weather...");
        }

        /// <summary>
        /// Gets the user details.
        /// </summary>
        /// <returns>FBUserDetails.</returns>
        public FBUserDetails GetUserDetails()
        {
            if (Details != null)
                return Details;
            else
                throw new FBNoData("No Data! Did You Close The Browser Without Authenticating?");

        }

        /// <summary>
        /// Gets the user likes.
        /// </summary>
        /// <returns>Dictionary&lt;System.String, FBUserLike&gt;.</returns>
        /// <exception cref="FBNoData">No Data! Did You Close The Browser Without Authenticating?</exception>
        public Dictionary<string, FBUserLike> GetUserLikes()
        {
            if (MyLikes.Count != 0 )
                return MyLikes;
            else
                throw new FBNoData("No Data! Did You Close The Browser Without Authenticating?");
        }

        /// <summary>
        /// Gets the user events.
        /// </summary>
        /// <returns>Dictionary&lt;System.String, FBUserEvent&gt;.</returns>
        public Dictionary<string, FBUserEvent> GetUserEvents()
        {
            if (MyEvents.Count !=0)
                return MyEvents;
            else
                throw new FBNoData("No Data! Did You Close The Browser Without Authenticating?");
        }
    }


}
