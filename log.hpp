#pragma once

#include <iostream>
#include <string>
#include <sstream>

enum LogLevel {
	DEBUG,
   	INFO,
   	WARNING,
   	ERROR,
	NONE
};

class Log{
	public:
		static void debug(const std::string&);
		static void info(const std::string&);
		static void warning(const std::string&);
		static void error(const std::string&);
	private:
		static LogLevel level;
		static const std::string color_reset;
		static const std::string color_error;
		static const std::string color_warning;
		static const std::string color_info;
		static const std::string color_debug;
		Log();	// Remove constructor
		~Log();	// Remove destructor
};
