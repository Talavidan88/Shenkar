// ***********************************************************************
// Assembly         : CSharp End Proj WS API
// Author           : Tal
// Created          : 05-12-2016
//
// Last Modified By : Tal
// Last Modified On : 05-12-2016
// ***********************************************************************
// <copyright file="Location.cs" company="">
//     Copyright ©  2016
// </copyright>
// <summary></summary>
// ***********************************************************************
namespace CSharp_End_Proj_WS_API
{
    /// <summary>
    /// Class Location.
    /// </summary>
    public class Location
    {
        /// <summary>
        /// Gets or sets the identifier.
        /// </summary>
        /// <value>The identifier.</value>
        public int id { get; set; }
        /// <summary>
        /// Gets or sets the name.
        /// </summary>
        /// <value>The name.</value>
        public string name { get; set; }
        /// <summary>
        /// Gets or sets the country.
        /// </summary>
        /// <value>The country.</value>
        public string country { get; set; }
        /// <summary>
        /// Gets or sets the coord.
        /// </summary>
        /// <value>The coord.</value>
        public WeatherService.OpenWeatherMap.Coord coord { get; set; }

        /// <summary>
        /// Initializes a new instance of the <see cref="Location"/> class.
        /// </summary>
        /// <param name="id">The identifier.</param>
        /// <param name="name">The name.</param>
        /// <param name="country">The country.</param>
        /// <param name="coor">The coor.</param>
        public Location(int id, string name = "", string country = "", WeatherService.OpenWeatherMap.Coord coor = null)
        {
            this.id = id;
            this.name = name;
            this.country = country;
            coord = coor;
        }

    }
}