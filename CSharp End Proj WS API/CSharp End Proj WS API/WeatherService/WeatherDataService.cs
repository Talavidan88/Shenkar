// ***********************************************************************
// Assembly         : CSharp End Proj WS API
// Author           : Tal
// Created          : 05-12-2016
//
// Last Modified By : Tal
// Last Modified On : 05-12-2016
// ***********************************************************************
// <copyright file="WeatherDataService.cs" company="">
//     Copyright ©  2016
// </copyright>
// <summary></summary>
// ***********************************************************************
using Newtonsoft.Json;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Net;
using System.Text;
using System.Threading.Tasks;

namespace CSharp_End_Proj_WS_API.WeatherService
{
    /// <summary>
    /// Class WeatherDataService.
    /// </summary>
    /// <seealso cref="CSharp_End_Proj_WS_API.IDataService" />
    public class WeatherDataService : IDataService
    {
        /// <summary>
        /// The appid
        /// </summary>
        private const string appid = "129ddaf285e829534e3b242ffdca3b06";
        /// <summary>
        /// The _instance
        /// </summary>
        private static readonly WeatherDataService _instance = new WeatherDataService(); //thread safe singleton object.
        /// <summary>
        /// Gets the instance.
        /// </summary>
        /// <value>The instance.</value>
        public static WeatherDataService Instance
        {
            get
            {
                return _instance;
            }
        }
        /// <summary>
        /// Prevents a default instance of the <see cref="WeatherDataService"/> class from being created.
        /// </summary>
        private WeatherDataService()
        {

        }
        /// <summary>
        /// Creates the query and return data.
        /// </summary>
        /// <param name="query">The query.</param>
        /// <returns>OpenWeatherMap.Root.</returns>
        /// <exception cref="WeatherNoSuchPlace"></exception>
        private OpenWeatherMap.Root CreateQueryAndReturnData(string query)
        {
            using (WebClient wc = new WebClient())
            {
                var json = wc.DownloadString(string.Format("http://api.openweathermap.org/data/2.5/weather?{0}&appid={1}&mode=json&units=metric",query, appid));
                WeatherService.OpenWeatherMap.Root obj = JsonConvert.DeserializeObject<WeatherService.OpenWeatherMap.Root>(json);
                if (obj.cod != 200)
                {
                    throw new WeatherNoSuchPlace(obj.message);
                }
                return obj;
            }
        }
        /// <summary>
        /// Gets the weather data.
        /// </summary>
        /// <param name="location">The location.</param>
        /// <returns>WeatherData.</returns>
        /// <exception cref="WeatherNoLocation"></exception>
        public OpenWeatherMap.Root GetWeatherData(Location location)
        {
            string querystr = string.Empty;
            if (location.id != 0)
            {
                querystr = "id="+ location.id.ToString();
                return CreateQueryAndReturnData(querystr);

            }
            if (location.coord != null)
            {
                querystr = "lat=" + location.coord.lat + "&lon=" + location.coord.lon;
                return CreateQueryAndReturnData(querystr);

            }
            if (location.name != string.Empty)
            {
                if (location.country != string.Empty)
                {
                    querystr = "q=" + location.name + "," + location.country;
                    return CreateQueryAndReturnData(querystr);

                }
                else
                {
                    querystr = "q=" + location.name;
                    return CreateQueryAndReturnData(querystr);
                }
            }
            throw new WeatherNoLocation();
        }

        /// <summary>
        /// Gets the user details.
        /// </summary>
        /// <returns>FBUserDetails.</returns>
        /// <exception cref="WeatherNoService"></exception>
        public FBUserDetails GetUserDetails()
        {
            throw new WeatherNoService();
        }

        /// <summary>
        /// Gets the user likes.
        /// </summary>
        /// <returns>Dictionary&lt;System.String, FBUserLike&gt;.</returns>
        /// <exception cref="WeatherNoService"></exception>
        public Dictionary<string, FBUserLike> GetUserLikes()
        {
            throw new WeatherNoService();
        }

        /// <summary>
        /// Gets the user events.
        /// </summary>
        /// <returns>Dictionary&lt;System.String, FBUserEvent&gt;.</returns>
        /// <exception cref="WeatherNoService"></exception>
        public Dictionary<string, FBUserEvent> GetUserEvents()
        {
            throw new WeatherNoService();
        }

        /// <summary>
        /// Authenticates this instance.
        /// </summary>
        /// <exception cref="WeatherNoService">Doesn't Need Authentication!</exception>
        public void Authenticate()
        {
            throw new WeatherNoService("Doesn't Need Authentication!");
        }

        /// <summary>
        /// Posts the specified MSG.
        /// </summary>
        /// <param name="msg">The MSG.</param>
        /// <returns>System.String.</returns>
        /// <exception cref="WeatherNoService"></exception>
        public string Post(string msg)
        {
            throw new WeatherNoService();
        }

        /// <summary>
        /// Deletes the specified identifier.
        /// </summary>
        /// <param name="id">The identifier.</param>
        /// <exception cref="WeatherNoService"></exception>
        public void Delete(string id)
        {
            throw new WeatherNoService();
        }
    }
}
