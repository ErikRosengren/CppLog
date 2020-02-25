#include "log.hpp"

int main(){
	std::cout << "This is a normal print" << std::endl;
	DEBUG("debug log");
	INFO("info log");
	WARNING("warning log with formatting " << 123 << "!");
	ERROR("error log");
	std::cout << "This is a normal print" << std::endl;
}
