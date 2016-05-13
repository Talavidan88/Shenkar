// ***********************************************************************
// Assembly         : CSharp End Proj WS API
// Author           : Tal
// Created          : 05-12-2016
//
// Last Modified By : Tal
// Last Modified On : 05-12-2016
// ***********************************************************************
// <copyright file="DataServiceFactory.cs" company="">
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
    /// Enum DataServices
    /// </summary>
    public enum DataServices{FACEBOOK,OPEN_WEATHER_MAP };
    /// <summary>
    /// Class DataServiceFactory.
    /// </summary>
    public static class DataServiceFactory
    {

        /// <summary>
        /// Gets the data service.
        /// </summary>
        /// <param name="site">The site.</param>
        /// <returns>IDataService.</returns>
        /// <exception cref="NoServiceException">We Don't Support  + site+  Service Yet</exception>
        public static IDataService GetDataService(DataServices site)
        {
            switch (site)
            {
                case DataServices.OPEN_WEATHER_MAP:
                    return WeatherDataService.Instance;
                case DataServices.FACEBOOK:
                    return MyFaceBook.Instance;
                default:
                    throw new NoServiceException("We Don't Support " + site+ " Service Yet");
            }
        }
    }
}
