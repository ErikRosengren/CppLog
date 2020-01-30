#include "log.hpp"

LogLevel Log::level = DEBUG;
std::string Log::file_path = "log.log";
bool Log::log_to_file = true;

int main(){
	std::cout << "This is a normal print" << std::endl;
	Log::debug("debug log");
	Log::info("info log");
	Log::warning("warning log");
	Log::error("error log");
	std::cout << "This is a normal print" << std::endl;
}
