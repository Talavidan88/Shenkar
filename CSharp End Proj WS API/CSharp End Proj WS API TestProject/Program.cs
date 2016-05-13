// ***********************************************************************
// Assembly         : CSharp End Proj WS API
// Author           : Tal
// Created          : 05-10-2016
//
// Last Modified By : Tal
// Last Modified On : 05-12-2016
// ***********************************************************************
// <copyright file="Program.cs" company="">
//     Copyright ©  2016
// </copyright>
// <summary></summary>
// ***********************************************************************
using System;
using System.Diagnostics;
using System.Runtime.InteropServices;


namespace CSharp_End_Proj_WS_API
{
    /// <summary>
    /// Class Program.
    /// </summary>
    class Program
    {
        /// <summary>
        /// Defines the entry point of the application.
        /// </summary>
        /// <param name="args">The arguments.</param>
        [STAThread] //must be single threaded!!! due to use of Windows.Forms (for facebook authentication)
        static void Main(string[] args)
        {
            try
            {
                Console.OutputEncoding = new System.Text.UTF8Encoding();  //for hebrew support, need to make sure CMD has courier new installed on registry.
                IDataService facebook = DataServiceFactory.GetDataService(DataServices.FACEBOOK);
                IDataService weather = DataServiceFactory.GetDataService(DataServices.OPEN_WEATHER_MAP);
                Console.WriteLine(weather.GetWeatherData(new Location(2172797)).ToString());
                Console.WriteLine(weather.GetWeatherData(new Location(0, "Ramatgan")).ToString());
                Console.WriteLine(weather.GetWeatherData(new Location(0, "newyour", "us")).ToString());
                Console.WriteLine(weather.GetWeatherData(new Location(0, "", "", new WeatherService.OpenWeatherMap.Coord(23.671, 53.683))).ToString());
                Console.WriteLine(weather.GetWeatherData(new Location(0, "Moscow")).ToString());

                facebook.Authenticate();
                Console.WriteLine(facebook.GetUserLikes()["Word Porn"].Liked_time.ToString());
                Console.WriteLine(facebook.ToString());
                string postId = facebook.Post("skdfssaddf");
                Process.Start("http://www.facebook.com/" + postId);
                facebook.Delete(postId);
                Process.Start("http://www.facebook.com/" + postId);

                Console.ReadLine();

            }
            catch (Exception e)
            {
                Console.WriteLine(e.Message);
                Console.ReadLine();
            }

        }
    }
}