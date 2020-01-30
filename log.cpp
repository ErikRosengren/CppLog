#include "log.hpp"

const std::string Log::color_reset=  "\033[0m";
const std::string Log::color_error = "\033[1;31m";
const std::string Log::color_warning= "\033[1;33m";
const std::string Log::color_info = "\033[1;34m";
const std::string Log::color_debug= "\033[1;95m";

void Log::debug(const std::string& input){
	if(Log::level != DEBUG || Log::level == NONE){
		return;
	}

	Log::put_line(color_debug, "DEBUG", input);
}

void Log::info(const std::string& input){
	if((Log::level != DEBUG && Log::level != INFO) || Log::level == NONE){
		return;
	}

	Log::put_line(color_info, "INFO", input);
}

void Log::warning(const std::string& input){
	if((Log::level != DEBUG && Log::level != INFO && Log::level != WARNING)  || Log::level == NONE){
		return;
	}

	Log::put_line(color_warning, "WARNING", input);
}

void Log::error(const std::string& input){
	if(Log::level == NONE){
		return;
	}

	Log::put_line(color_error, "ERROR", input);
}

void Log::put_line(const std::string& color, const std::string& level, const std::string& input){
	auto t = std::time(nullptr);
	auto tm = *std::localtime(&t);
	std::stringstream ss;
	ss << std::put_time(&tm, "%Y-%m-%d %H:%M:%S: ");
	std::string timestamp = ss.str();

	std::cout << color << timestamp << input << color_reset << std::endl;

	if(Log::log_to_file){
		Log::write_to_file(level, timestamp, input);
	}
}

void Log::write_to_file(const std::string& level, const std::string& timestamp, const std::string& input){
	std::fstream file;

	file.open(Log::file_path, std::fstream::in | std::fstream::out | std::fstream::app);

	if(!file){
		file.open(Log::file_path, std::fstream::in | std::fstream::out | std::fstream::trunc);
		file << level << " - " << timestamp << input << std::endl;
		file.close();
	} else {
		file << level << " - " << timestamp << input << std::endl;
		file.close();
	}
}
