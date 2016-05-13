// ***********************************************************************
// Assembly         : CSharp End Proj WS API
// Author           : Tal
// Created          : 05-12-2016
//
// Last Modified By : Tal
// Last Modified On : 05-12-2016
// ***********************************************************************
// <copyright file="FBException.cs" company="">
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
    /// Class FBNoData.
    /// </summary>
    /// <seealso cref="System.Exception" />
    public class FBNoData : Exception
    {
        /// <summary>
        /// Initializes a new instance of the <see cref="FBNoData"/> class.
        /// </summary>
        /// <param name="msg">The MSG.</param>
        public FBNoData(string msg) : base(msg) { }
    }
    /// <summary>
    /// Class FBAlreadyAuthenticated.
    /// </summary>
    /// <seealso cref="System.Exception" />
    public class FBAlreadyAuthenticated : Exception
    {
        /// <summary>
        /// Initializes a new instance of the <see cref="FBAlreadyAuthenticated"/> class.
        /// </summary>
        /// <param name="msg">The MSG.</param>
        public FBAlreadyAuthenticated(string msg) : base(msg) { }
    }
    /// <summary>
    /// Class FBUserDeclined.
    /// </summary>
    /// <seealso cref="System.Exception" />
    public class FBUserDeclined : Exception
    {
        /// <summary>
        /// Initializes a new instance of the <see cref="FBUserDeclined"/> class.
        /// </summary>
        /// <param name="msg">The MSG.</param>
        public FBUserDeclined(string msg = "User Decliend To Give Permissions") : base(msg) { }
    }
    /// <summary>
    /// Class FBUserDuplicatePost.
    /// </summary>
    /// <seealso cref="System.Exception" />
    public class FBUserDuplicatePost : Exception
    {
        /// <summary>
        /// Initializes a new instance of the <see cref="FBUserDuplicatePost"/> class.
        /// </summary>
        /// <param name="msg">The MSG.</param>
        public FBUserDuplicatePost(string msg = "Post Exists!") : base(msg)
        {
        }
    }
}