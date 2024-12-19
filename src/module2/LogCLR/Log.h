#pragma once

#include <cstdint>

namespace sys = System;
namespace diagnostics = System::Diagnostics;

namespace LogCLR {
	public enum class LogType : uint8_t {
		Information,
		Warning,
		Error
	};

	public ref class Log {
	private:
		sys::String^ source;
	public:
		Log();
		void Write(sys::String^ message, LogType type);
		void Message(sys::String^ message);
		void Warning(sys::String^ message);
		void Failure(sys::String^ message);

		property sys::String^ Source {
			sys::String^ get() { return source; }
			void set(sys::String^ value) { source = value; }
		}
	};
}
