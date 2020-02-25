#include "log.hpp"

namespace Log {

	namespace {
		void write_to_file(const std::string& level, const std::string& timestamp, const std::string& input){
			std::fstream file;

			file.open(file_path, std::fstream::in | std::fstream::out | std::fstream::app);

			if(!file){
				file.open(file_path, std::fstream::in | std::fstream::out | std::fstream::trunc);
			}

			file << level << timestamp << input;
			file.close();
		}

		void put_line(const std::string& color, const std::string& level, const std::string& input){
			auto t = std::time(nullptr);
			auto tm = *std::localtime(&t);
			std::stringstream ss;
			ss << std::put_time(&tm, "%Y-%m-%d %H:%M:%S: ");
			std::string timestamp = ss.str();

			std::cout << color << level << timestamp << color_reset << input;

			if(log_to_file){
				write_to_file(level, timestamp, input);
			}
		}
	}

	void debug(const std::string input){
		if(level != LEVEL_DEBUG || level == LEVEL_NONE){
			return;
		}

		put_line(color_debug, "DEBUG ", input);
	}

	void info(const std::string input){
		if((level != LEVEL_DEBUG && level != LEVEL_INFO) || level == LEVEL_NONE){
			return;
		}

		put_line(color_info, "INFO  ", input);
	}

	void warning(const std::string input){
		if((level != LEVEL_DEBUG && level != LEVEL_INFO && level != LEVEL_WARNING)  || level == LEVEL_NONE){
			return;
		}

		put_line(color_warning, "WARN  ", input);
	}

	void error(const std::string input){
		if(level == LEVEL_NONE){
			return;
		}

		put_line(color_error, "ERROR ", input);
	}
}
