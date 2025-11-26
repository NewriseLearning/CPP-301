// MyLog1.cpp

#include "MyLog.h"
#include <array>

namespace mylog {

	const std::_tstring& GetLogTypeString(LogType type) {
		static std::array<std::_tstring, 4> strings = {
			std::_tstring(_t("Information")),
			std::_tstring(_t("Warning")),
			std::_tstring(_t("Error")),
			std::_tstring(_t("Message"))
		};

		auto index = (uint16_t)type;
		if (index < 0 || index > 2) index = 3;
		return strings[index];
	}


}	// namespace mylog

