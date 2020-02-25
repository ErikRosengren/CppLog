#pragma once

#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <ctime>
#include <fstream>

#define DEBUG(input)				\
	{								\
		std::stringstream ss;		\
		ss << input << std::endl;	\
		Log::debug(ss.str());		\
	}

#define INFO(input)					\
	{								\
		std::stringstream ss;		\
		ss << input << std::endl;	\
		Log::info(ss.str());		\
	}

#define WARNING(input)				\
	{								\
		std::stringstream ss;		\
		ss << input << std::endl;	\
		Log::warning(ss.str());		\
	}

#define ERROR(input)				\
	{								\
		std::stringstream ss;		\
		ss << input << std::endl;	\
		Log::error(ss.str());		\
	}

namespace Log {

	namespace {
		enum LogLevel {
			LEVEL_DEBUG,
			LEVEL_INFO,
			LEVEL_WARNING,
			LEVEL_ERROR,
			LEVEL_NONE
		};

		// Config goes here
		const LogLevel level = LEVEL_DEBUG;
		const bool log_to_file = true;
		const std::string file_path = "out.log"; // Note: relative path.

		// ANSI color escape codes
		const std::string color_reset=  "\033[0m";			// Reset formatting
		const std::string color_error = "\033[1;31m";		// Red
		const std::string color_warning= "\033[1;33;5m";		// Yellow
		const std::string color_info = "\033[1;34m";		// Blue
		const std::string color_debug= "\033[1;95m";		// Magenta
	}

	void debug(std::string);
	void info(std::string);
	void warning(std::string);
	void error(std::string);
}
