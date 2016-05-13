// ***********************************************************************
// Assembly         : CSharp End Proj WS API
// Author           : Tal
// Created          : 05-12-2016
//
// Last Modified By : Tal
// Last Modified On : 05-12-2016
// ***********************************************************************
// <copyright file="OpenWeatherMap.cs" company="">
//     Copyright ©  2016
// </copyright>
// <summary></summary>
// ***********************************************************************
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CSharp_End_Proj_WS_API.WeatherService
{
    /// <summary>
    /// Class OpenWeatherMap.
    /// </summary>
    public class OpenWeatherMap
    {
        /// <summary>
        /// Class Coord.
        /// </summary>
        public class Coord
        {
            /// <summary>
            /// Gets or sets the lon.
            /// </summary>
            /// <value>The lon.</value>
            public double lon { get; set; }
            /// <summary>
            /// Gets or sets the lat.
            /// </summary>
            /// <value>The lat.</value>
            public double lat { get; set; }
            /// <summary>
            /// Initializes a new instance of the <see cref="Coord"/> class.
            /// </summary>
            /// <param name="lon">The lon.</param>
            /// <param name="lat">The lat.</param>
            public Coord(double lon, double lat)
            {
                this.lon = lon;
                this.lat = lat;
            }
            /// <summary>
            /// Returns a <see cref="System.String" /> that represents this instance.
            /// </summary>
            /// <returns>A <see cref="System.String" /> that represents this instance.</returns>
            public override string ToString()
            {
                return "\nCoordinates are - longitude: " + lon + " latitude: " + lat;
            }
        }

        /// <summary>
        /// Class Sys.
        /// </summary>
        public class Sys
        {
            /// <summary>
            /// Gets or sets the type.
            /// </summary>
            /// <value>The type.</value>
            public int type { get; set; }
            /// <summary>
            /// Gets or sets the identifier.
            /// </summary>
            /// <value>The identifier.</value>
            public int id { get; set; }
            /// <summary>
            /// Gets or sets the message.
            /// </summary>
            /// <value>The message.</value>
            public double message { get; set; }
            /// <summary>
            /// Gets or sets the country.
            /// </summary>
            /// <value>The country.</value>
            public string country { get; set; }
            /// <summary>
            /// Gets or sets the sunrise.
            /// </summary>
            /// <value>The sunrise.</value>
            public int sunrise { get; set; }
            /// <summary>
            /// Gets or sets the sunset.
            /// </summary>
            /// <value>The sunset.</value>
            public int sunset { get; set; }
            /// <summary>
            /// Fixes the epoch.
            /// </summary>
            /// <param name="epoch">The epoch.</param>
            /// <returns>DateTime.</returns>
            private DateTime fixEpoch(long epoch)
            {
                var e = new DateTime(1970, 1, 1, 0, 0, 0, DateTimeKind.Utc);
                return e.AddSeconds(epoch);
            }
            /// <summary>
            /// Returns a <see cref="System.String" /> that represents this instance.
            /// </summary>
            /// <returns>A <see cref="System.String" /> that represents this instance.</returns>
            public override string ToString()
            {
                string str = "\n<<<<<<System Data>>>>>>";
                if (id != 0)
                {
                    str += "\nID is: " + id.ToString();
                }
                if (country != "")
                {
                    str += "\nCountry Code is: " + country;
                }
                if (sunrise != 0)
                {
                    str += "\nSunrise's at: " + fixEpoch(sunrise).ToString();
                }
                if (sunset != 0)
                {
                    str += "\nSunrise's at: " + fixEpoch(sunset).ToString();
                }
                return str;
            }
        }

        /// <summary>
        /// Class Weather.
        /// </summary>
        public class Weather
        {
            /// <summary>
            /// Gets or sets the identifier.
            /// </summary>
            /// <value>The identifier.</value>
            public int id { get; set; }
            /// <summary>
            /// Gets or sets the main.
            /// </summary>
            /// <value>The main.</value>
            public string main { get; set; }
            /// <summary>
            /// Gets or sets the description.
            /// </summary>
            /// <value>The description.</value>
            public string description { get; set; }
            /// <summary>
            /// Gets or sets the icon.
            /// </summary>
            /// <value>The icon.</value>
            public string icon { get; set; }
            /// <summary>
            /// Returns a <see cref="System.String" /> that represents this instance.
            /// </summary>
            /// <returns>A <see cref="System.String" /> that represents this instance.</returns>
            public override string ToString()
            {
                return "\nWeather Description: " + description;
            }
        }

        /// <summary>
        /// Class Main.
        /// </summary>
        public class Main
        {
            /// <summary>
            /// Gets or sets the temporary.
            /// </summary>
            /// <value>The temporary.</value>
            public double temp { get; set; }
            /// <summary>
            /// Gets or sets the humidity.
            /// </summary>
            /// <value>The humidity.</value>
            public int humidity { get; set; }
            /// <summary>
            /// Gets or sets the pressure.
            /// </summary>
            /// <value>The pressure.</value>
            public double pressure { get; set; }
            /// <summary>
            /// Gets or sets the temp_min.
            /// </summary>
            /// <value>The temp_min.</value>
            public double temp_min { get; set; }
            /// <summary>
            /// Gets or sets the temp_max.
            /// </summary>
            /// <value>The temp_max.</value>
            public double temp_max { get; set; }
            /// <summary>
            /// Returns a <see cref="System.String" /> that represents this instance.
            /// </summary>
            /// <returns>A <see cref="System.String" /> that represents this instance.</returns>
            public override string ToString()
            {
                return "\n<<<<<<Temperature Data>>>>>>\nTemp is: " + temp.ToString() + " Humidity is: " + humidity.ToString() + " Pressure is: " + pressure.ToString();
            }
        }

        /// <summary>
        /// Class Wind.
        /// </summary>
        public class Wind
        {
            /// <summary>
            /// Gets or sets the speed.
            /// </summary>
            /// <value>The speed.</value>
            public double speed { get; set; }
            /// <summary>
            /// Gets or sets the gust.
            /// </summary>
            /// <value>The gust.</value>
            public double gust { get; set; }
            /// <summary>
            /// Gets or sets the deg.
            /// </summary>
            /// <value>The deg.</value>
            public float deg { get; set; }
            /// <summary>
            /// Returns a <see cref="System.String" /> that represents this instance.
            /// </summary>
            /// <returns>A <see cref="System.String" /> that represents this instance.</returns>
            public override string ToString()
            {
                return "\n<<<<<<Wind Data>>>>>>\nSpeed is: " + speed.ToString() + " Gust is: " + gust.ToString() + " Direction is: " + deg.ToString() + "°";
            }
        }



        /// <summary>
        /// Class Clouds.
        /// </summary>
        public class Clouds
        {
            /// <summary>
            /// Gets or sets all.
            /// </summary>
            /// <value>All.</value>
            public int all { get; set; }
            /// <summary>
            /// Returns a <see cref="System.String" /> that represents this instance.
            /// </summary>
            /// <returns>A <see cref="System.String" /> that represents this instance.</returns>
            public override string ToString()
            {
                return "\nCloudiness is: " + all.ToString() + "%";
            }
        }

        /// <summary>
        /// Class Root.
        /// </summary>
        public class Root
        {
            /// <summary>
            /// Gets or sets the coord.
            /// </summary>
            /// <value>The coord.</value>
            public Coord coord { get; set; }
            /// <summary>
            /// Gets or sets the system.
            /// </summary>
            /// <value>The system.</value>
            public Sys sys { get; set; }
            /// <summary>
            /// Gets or sets the weather.
            /// </summary>
            /// <value>The weather.</value>
            public List<Weather> weather { get; set; }
            /// <summary>
            /// Gets or sets the base.
            /// </summary>
            /// <value>The base.</value>
            public string @base { get; set; }
            /// <summary>
            /// Gets or sets the main.
            /// </summary>
            /// <value>The main.</value>
            public Main main { get; set; }
            /// <summary>
            /// Gets or sets the wind.
            /// </summary>
            /// <value>The wind.</value>
            public Wind wind { get; set; }
            /// <summary>
            /// Gets or sets the rain.
            /// </summary>
            /// <value>The rain.</value>
            public Dictionary<string, double> rain { get; set; }
            /// <summary>
            /// Gets or sets the clouds.
            /// </summary>
            /// <value>The clouds.</value>
            public Clouds clouds { get; set; }
            /// <summary>
            /// Gets or sets the dt.
            /// </summary>
            /// <value>The dt.</value>
            public int dt { get; set; }
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
            /// Gets or sets the cod.
            /// </summary>
            /// <value>The cod.</value>
            public int cod { get; set; }
            /// <summary>
            /// Gets or sets the message.
            /// </summary>
            /// <value>The message.</value>
            public string message { get; set; }

            /// <summary>
            /// Returns a <see cref="System.String" /> that represents this instance.
            /// </summary>
            /// <returns>A <see cref="System.String" /> that represents this instance.</returns>
            public override string ToString()
            {
                string wstr="",rstr = "\n";
                foreach(Weather w in weather)
                {
                    wstr += w.ToString();
                }
                if (rain != null)
                    foreach (KeyValuePair<string, double> kvp in rain)
                    {
                        rstr += kvp.Key + " " + kvp.Value.ToString();
                    }
                else
                    rstr += "No Rain";
                return "<<<<<<Weather Data For " + name + ">>>>>>\n" + coord.ToString() + sys.ToString() + wstr + main.ToString() + wind.ToString() + rstr + clouds.ToString();
            }
        }
    }
}
