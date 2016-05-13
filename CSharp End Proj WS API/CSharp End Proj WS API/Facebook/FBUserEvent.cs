// ***********************************************************************
// Assembly         : CSharp End Proj WS API
// Author           : Tal
// Created          : 05-12-2016
//
// Last Modified By : Tal
// Last Modified On : 05-12-2016
// ***********************************************************************
// <copyright file="FBUserEvent.cs" company="">
//     Copyright ©  2016
// </copyright>
// <summary></summary>
// ***********************************************************************
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CSharp_End_Proj_WS_API
{
    /// <summary>
    /// Class FBUserEvent.
    /// </summary>
    public class FBUserEvent
    {
        /// <summary>
        /// Event's name
        /// </summary>
        private string name;
        /// <summary>
        /// Event's description
        /// </summary>
        private string description;
        /// <summary>
        /// Event's start time
        /// </summary>
        private string start_time;
        /// <summary>
        /// Initializes a new instance of the <see cref="FBUserEvent"/> class.
        /// </summary>
        /// <param name="name">The name.</param>
        /// <param name="des">The description.</param>
        /// <param name="st">The start time.</param>
        public FBUserEvent(string name,string des,string st)
        {
            bool hebname = false, hebabout = false;
            char heb = 'א';

            for (int i = 0; i < 26; i++, heb++)
            {
                if (name.Contains(heb))
                    hebname = true;
                if (des != null)
                    if (des.Contains(heb))
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
            if (hebabout)
            {
                char[] arr = des.ToCharArray();
                Array.Reverse(arr);
                Description = new string(arr);
            }
            else
                Description = des;
            StartTime = st;
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
        /// Gets or sets the description.
        /// </summary>
        /// <value>The description.</value>
        public string Description
        {
            private set
            {
                if (value == null)
                    description = "Unavailable";
                else
                    description = value;
            }
            get
            {
                return description;
            }
        }
        /// <summary>
        /// Gets or sets the start time.
        /// </summary>
        /// <value>The start time.</value>
        public string StartTime
        {
            private set
            {
                if (value == null)
                    start_time = "Unavailable";
                else
                    start_time = value;
            }
            get
            {
                return start_time;
            }
        }
        /// <summary>
        /// Returns a <see cref="System.String" /> that represents this instance.
        /// </summary>
        /// <returns>A <see cref="System.String" /> that represents this instance.</returns>
        public override string ToString()
        {
            return  "<<<<<<FaceBook Event Details>>>>>>\nName is: " + Name + "\nStart Time is: " + StartTime + "\nDescription is: " + Description+ "\n\n==============================\n";
        }
    }
}
