var logger = new ActiveXObject("LogCom.Log")
logger.Source = "C:\\CPP-301\\UseLogCom2.log"
logger.Write("Hello!")
logger.Write("Goodbye!")
WScript.Echo("Done")
logger = null
