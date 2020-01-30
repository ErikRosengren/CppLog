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

	std::cout << color_debug << input << color_reset << std::endl;
}

void Log::info(const std::string& input){
	if((Log::level != DEBUG && Log::level != INFO) || Log::level == NONE){
		return;
	}
	std::cout << color_info << input << color_reset << std::endl;
}

void Log::warning(const std::string& input){
	if((Log::level != DEBUG && Log::level != INFO && Log::level != WARNING)  || Log::level == NONE){
		return;
	}
	std::cout << color_warning << input << color_reset << std::endl;
}

void Log::error(const std::string& input){
	if(Log::level == NONE){
		return;
	}
	std::cout << color_error << input << color_reset << std::endl;
}
