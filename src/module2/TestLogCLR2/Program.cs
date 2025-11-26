using System;

namespace TestLogCLR2 {
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

