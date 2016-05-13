// ***********************************************************************
// Assembly         : CSharp End Proj WS API
// Author           : Tal
// Created          : 05-12-2016
//
// Last Modified By : Tal
// Last Modified On : 05-12-2016
// ***********************************************************************
// <copyright file="IDataService.cs" company="">
//     Copyright ©  2016
// </copyright>
// <summary></summary>
// ***********************************************************************
using CSharp_End_Proj_WS_API.WeatherService;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CSharp_End_Proj_WS_API
{
    /// <summary>
    /// Interface IDataService
    /// </summary>
    public interface IDataService
    {
        /// <summary>
        /// Gets the weather data.
        /// </summary>
        /// <param name="location">The location.</param>
        /// <returns>WeatherData.</returns>
        OpenWeatherMap.Root GetWeatherData(Location location);

        /// <summary>
        /// Gets the user details.
        /// </summary>
        /// <returns>FBUserDetails.</returns>
        FBUserDetails GetUserDetails();
        /// <summary>
        /// Gets the user likes.
        /// </summary>
        /// <returns>Dictionary&lt;System.String, FBUserLike&gt;.</returns>
        Dictionary<string, FBUserLike> GetUserLikes();
        /// <summary>
        /// Gets the user events.
        /// </summary>
        /// <returns>Dictionary&lt;System.String, FBUserEvent&gt;.</returns>
        Dictionary<string, FBUserEvent> GetUserEvents();
        /// <summary>
        /// Authenticates this instance.
        /// </summary>
        void Authenticate();
        /// <summary>
        /// Posts the specified MSG.
        /// </summary>
        /// <param name="msg">The MSG.</param>
        /// <returns>System.String.</returns>
        string Post(string msg);
        /// <summary>
        /// Deletes the specified identifier.
        /// </summary>
        /// <param name="id">The identifier.</param>
        void Delete(string id);
    }
}
