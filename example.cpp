#include "log.hpp"

int main(){
	std::cout << "This is a normal print" << std::endl;
	Log::debug("debug log");
	Log::info("info log");
	Log::warning("warning log");
	Log::error("error log");
	std::cout << "This is a normal print" << std::endl;
}
