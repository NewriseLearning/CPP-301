set logger = CreateObject("LogCom.Log")
logger.Source = "C:\CPP-301\UseLogCom1.log"
logger.Write "Hello!"
logger.Write "Goodbye!"
WScript.Echo "Done"
set logger = Nothing
