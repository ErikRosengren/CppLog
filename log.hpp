#pragma once

#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <ctime>
#include <fstream>

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
		static bool log_to_file;
		static std::string file_path;
		static const std::string color_reset;
		static const std::string color_error;
		static const std::string color_warning;
		static const std::string color_info;
		static const std::string color_debug;
		static void put_line(const std::string& color, const std::string& level,  const std::string& input);
		static void write_to_file(const std::string& level, const std::string& timestamp, const std::string& input);
		Log();	// Remove constructor
		~Log();	// Remove destructor
};
