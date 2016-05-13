// ***********************************************************************
// Assembly         : CSharp End Proj WS API
// Author           : Tal
// Created          : 05-12-2016
//
// Last Modified By : Tal
// Last Modified On : 05-12-2016
// ***********************************************************************
// <copyright file="FBUserDetails.cs" company="">
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
    /// Class FBUserDetails.
    /// </summary>
    public class FBUserDetails
    {
        /// <summary>
        /// Users birthday
        /// </summary>
        private string birthday;
        /// <summary>
        /// Users name
        /// </summary>
        private string name;
        /// <summary>
        /// Users email
        /// </summary>
        private string email;
        /// <summary>
        /// Users identifier
        /// </summary>
        private string id;
        /// <summary>
        /// Initializes a new instance of the <see cref="FBUserDetails"/> class.
        /// </summary>
        /// <param name="name">Users name.</param>
        /// <param name="bd">Users bd.</param>
        /// <param name="mail">Users mail.</param>
        /// <param name="id">Users identifier.</param>
        public FBUserDetails(string name,string bd,string mail,string id)
        {
            Name = name;
            Birthday = bd;
            Email = mail;
            Id = id;
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
        /// Gets or sets the birthday.
        /// </summary>
        /// <value>The birthday.</value>
        public string Birthday
        {
            private set
            {
                if (value == null)
                    birthday = "Unavailable";
                else
                    birthday = value;
            }
            get
            {
                return birthday;
            }
        }
        /// <summary>
        /// Gets or sets the email.
        /// </summary>
        /// <value>The email.</value>
        public string Email
        {
            private set
            {
                if (value == null)
                    email = "Unavailable";
                else
                    email = value;
            }
            get
            {
                return email;
            }
        }
        /// <summary>
        /// Returns a <see cref="System.String" /> that represents this instance.
        /// </summary>
        /// <returns>A <see cref="System.String" /> that represents this instance.</returns>
        public override string ToString() {
            return "<<<<<<FaceBook Details>>>>>>\nName is: " + Name + "\nBirthDay is: " + Birthday + "\nEmail is: " + Email + "\nFacebook ID is: " + Id + "\n\n==============================\n";
        }
        
    }
}
