#include "pch.h"
#include "Log.h"

namespace LogCLR {

	Log::Log() {
		source = L"Log";
	}

	void Log::Write(sys::String^ message, LogType type) {
		auto text = sys::String::Format("[{0}]{1}(\"{2}\")",
			source, type, message);
		diag::Debug::WriteLine(text);
	}

	void Log::Message(sys::String^ message) {
		Write(message, LogType::Information);
	}

	void Log::Warning(sys::String^ message) {
		Write(message, LogType::Warning);
	}

	void Log::Failure(sys::String^ message) {
		Write(message, LogType::Error);
	}
}
