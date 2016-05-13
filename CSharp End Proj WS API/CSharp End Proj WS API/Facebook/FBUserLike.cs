// ***********************************************************************
// Assembly         : CSharp End Proj WS API
// Author           : Tal
// Created          : 05-12-2016
//
// Last Modified By : Tal
// Last Modified On : 05-12-2016
// ***********************************************************************
// <copyright file="FBUserLike.cs" company="">
//     Copyright ©  2016
// </copyright>
// <summary></summary>
// ***********************************************************************
using Newtonsoft.Json.Linq;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CSharp_End_Proj_WS_API
{
    /// <summary>
    /// Class FBUserLike.
    /// </summary>
    public class FBUserLike
    {
        /// <summary>
        /// Like's name
        /// </summary>
        private string name;
        /// <summary>
        /// Like's about
        /// </summary>
        private string about;
        /// <summary>
        /// Like's identifier
        /// </summary>
        private string id;
        /// <summary>
        /// The time the User Liked this page
        /// </summary>
        private string liked_time;
        /// <summary>
        /// Initializes a new instance of the <see cref="FBUserLike"/> class.
        /// </summary>
        /// <param name="name">The name.</param>
        /// <param name="id">The identifier.</param>
        /// <param name="LikedTime">The liked time.</param>
        /// <param name="about">The about.</param>
        public FBUserLike(string name,string id,string LikedTime,string about)
        {
            bool hebname = false,hebabout = false;
            char heb = 'א';
            
            for (int i = 0; i < 26; i++,heb++)
            {
                if (name.Contains(heb))
                    hebname = true;
                if (about != null)
                    if (about.Contains(heb))
                        hebabout = true;
            }
            if (hebname)
            {
                char[] arr = name.ToCharArray();
                Array.Reverse(arr);
                Name = new string(arr);
            }
            else
                Name = name;
            Id = id;
            Liked_time = LikedTime;
            if (hebabout)
            {
                char[] arr = about.ToCharArray();
                Array.Reverse(arr);
                About = new string(arr);
            }
            else
                About = about;
        }

        /// <summary>
        /// Gets or sets the name.
        /// </summary>
        /// <value>The name.</value>
        public string Name
        {
            private set
            {
                if (value == null)
                    name = "Unavailable";
                else
                    name = value;
            }
            get
            {
                return name;
            }
        }
        /// <summary>
        /// Gets or sets the identifier.
        /// </summary>
        /// <value>The identifier.</value>
        public string Id
        {
            private set
            {
                if (value == null)
                    id = "Unavailable";
                else
                    id = value;
            }
            get
            {
                return id;
            }
        }
        /// <summary>
        /// Gets or sets the liked_time.
        /// </summary>
        /// <value>The liked_time.</value>
        public string Liked_time
        {
            private set
            {
                if (value == null)
                    liked_time = "Unavailable";
                else
                    liked_time = value;
            }
            get
            {
                return liked_time;
            }
        }
        /// <summary>
        /// Gets or sets the about.
        /// </summary>
        /// <value>The about.</value>
        public string About
        {
            private set
            {
                if (value == null)
                    about = "Unavailable";
                else
                    about = value;
            }
            get
            {
                return about;
            }
        }
        /// <summary>
        /// Returns a <see cref="System.String" /> that represents this instance.
        /// </summary>
        /// <returns>A <see cref="System.String" /> that represents this instance.</returns>
        public override string ToString()
        {
            return "<<<<<<FaceBook Likes Details>>>>>>\nName is: " + Name + "\nID is: " + Id + "\nLiked On: " + Liked_time + "\nDescription is: " + About + "\n\n==============================\n";
        }
    }
}
