#include "pch.h"

namespace LogCLR {
	Log::Log() {
		source = L"Log";
	}

	void Log::Write(sys::String^ message, LogType type) {
		auto text = sys::String::Format("[{0}] {1}(\"{2}\")",
			source, type, message);
		sys::Console::WriteLine(text);
		diagnostics::Debug::WriteLine(text);
		msclr::interop::marshal_context context;
		auto cpp_string = msclr::interop::marshal_as<std::wstring>(text);
		auto c_string = context.marshal_as<const char*>(text);
		std::wcout << cpp_string << std::endl;
		puts(c_string);
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