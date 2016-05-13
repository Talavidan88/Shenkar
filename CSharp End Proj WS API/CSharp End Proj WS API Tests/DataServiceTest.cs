using System;
using CSharp_End_Proj_WS_API;
using Microsoft.VisualStudio.TestTools.UnitTesting;
using CSharp_End_Proj_WS_API.WeatherService;

namespace CSharp_End_Proj_WS_API_Tests
{
    [TestClass]
    public class DataServiceTest
    {
        WeatherDataService ds;
        MyFaceBook fb;
        [TestInitialize]
        public void TestInitialize()
        {
            fb = MyFaceBook.Instance;
            ds = WeatherDataService.Instance;
        }
        [TestMethod]
        public void isSingleton()
        {
            MyFaceBook fb2 = MyFaceBook.Instance;
            WeatherDataService ds2 = WeatherDataService.Instance;
            Assert.AreEqual(fb2, fb);
            Assert.AreEqual(ds2, ds);
        }
        [TestMethod]
        [ExpectedException(typeof(NoServiceException))]
        public void NoServiceExceptionTest()
        {

                DataServices ds1 = (DataServices)4;
                IDataService ds = DataServiceFactory.GetDataService(ds1);
        }
        [TestMethod]
        [ExpectedException(typeof(WeatherNoLocation))]
        public void GetWeatherDataExceptionTest()
        {
            ds.GetWeatherData(new Location(0));
        }
        [TestMethod]
        [ExpectedException(typeof(WeatherNoSuchPlace))]
        public void GetWeatherDataException2Test()
        {
            ds.GetWeatherData(new Location(486486684));
        }
        [TestMethod]
        public void GetWeatherDataTest()
        {
            ds.GetWeatherData(new Location(0, "RamatGan"));
            OpenWeatherMap.Root map = new OpenWeatherMap.Root();
            map.name = "London";
            Assert.AreNotEqual(map.name, ds.GetWeatherData(new Location(0, "RamatGan")).name);
        }

        [TestCleanup]
        public void TestCleanup()
        {
            ds = null;
            fb = null;
        }
    }
}
