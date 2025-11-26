using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace TestLogCLR {
	class Program {
		static void Main(string[] args) {
			var log = new LogCLR.Log();
			log.Source = "TestLogCLR";
			log.Message("Hello!");
			log.Message("Goodbye!");
			log = null;
		//	GC.Collect();
		}
	}
}
