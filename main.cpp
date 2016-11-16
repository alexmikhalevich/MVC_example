#include "ccontroller.hpp"

int main(int argc, char** argv) {
	CController controller;
	int ret = 1;
	do {
		try {
			std::string command;
			std::getline(std::cin, command);
			ret = controller.parse_command(command);
		} catch(IException* e) {
			std::cerr << e->what() << std::endl;
			ret = controller.parse_command("help");
		}
	} while(ret == 1);

	return 0;
}
