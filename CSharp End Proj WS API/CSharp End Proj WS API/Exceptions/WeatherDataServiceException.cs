// ***********************************************************************
// Assembly         : CSharp End Proj WS API
// Author           : Tal
// Created          : 05-12-2016
//
// Last Modified By : Tal
// Last Modified On : 05-12-2016
// ***********************************************************************
// <copyright file="WeatherDataServiceException.cs" company="">
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
    /// Class WeatherNoService.
    /// </summary>
    /// <seealso cref="System.Exception" />
    public class WeatherNoService : Exception
    {
        /// <summary>
        /// Initializes a new instance of the <see cref="WeatherNoService"/> class.
        /// </summary>
        /// <param name="msg">The MSG.</param>
        public WeatherNoService(string msg = "Weather Data Service Can't Do that. yet...") : base(msg) { }
    }
    /// <summary>
    /// Class WeatherNoLocation.
    /// </summary>
    /// <seealso cref="System.Exception" />
    public class WeatherNoLocation : Exception
    {
        /// <summary>
        /// Initializes a new instance of the <see cref="WeatherNoLocation"/> class.
        /// </summary>
        /// <param name="msg">The MSG.</param>
        public WeatherNoLocation(string msg = "No Location Details!") : base(msg) { }
    }
    /// <summary>
    /// Class WeatherNoSuchPlace.
    /// </summary>
    /// <seealso cref="System.Exception" />
    public class WeatherNoSuchPlace : Exception
    {
        /// <summary>
        /// Initializes a new instance of the <see cref="WeatherNoSuchPlace"/> class.
        /// </summary>
        /// <param name="msg">The MSG.</param>
        public WeatherNoSuchPlace(string msg = "No Such City!") : base(msg) { }
    }

}
