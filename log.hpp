#pragma once

#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <ctime>
#include <fstream>


namespace Log{

	enum LogLevel {
		DEBUG,
		INFO,
		WARNING,
		ERROR,
		NONE
	};

	const LogLevel level = DEBUG;
	const bool log_to_file = true;
	const std::string file_path = "log.log" ;

	const std::string color_reset=  "\033[0m";			// Reset formatting
	const std::string color_error = "\033[1;31m";		// Red
	const std::string color_warning= "\033[1;33m";		// Yellow
	const std::string color_info = "\033[1;34m";		// Blue
	const std::string color_debug= "\033[1;95m";		// Magenta

	void debug(const std::string&);
	void info(const std::string&);
	void warning(const std::string&);
	void error(const std::string&);
}
