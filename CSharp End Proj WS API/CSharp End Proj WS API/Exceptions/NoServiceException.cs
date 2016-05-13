// ***********************************************************************
// Assembly         : CSharp End Proj WS API
// Author           : Tal
// Created          : 05-12-2016
//
// Last Modified By : Tal
// Last Modified On : 05-12-2016
// ***********************************************************************
// <copyright file="NoServiceException.cs" company="">
//     Copyright ©  2016
// </copyright>
// <summary></summary>
// ***********************************************************************
using System;
using System.Runtime.Serialization;

namespace CSharp_End_Proj_WS_API
{

    /// <summary>
    /// Class NoServiceException.
    /// </summary>
    /// <seealso cref="System.Exception" />
    public class NoServiceException : Exception
    {
        /// <summary>
        /// Initializes a new instance of the <see cref="NoServiceException"/> class.
        /// </summary>
        /// <param name="msg">The MSG.</param>
        public NoServiceException(string msg) : base(msg)
        {
        }
    }
}