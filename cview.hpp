#ifndef CVIEW_HPP
#define CVIEW_HPP

#include <iostream>

class CView {
	private:
		static void _input_invitation() {
			std::cout << "> ";
		}
	public:
		static void show_greeting() {
			std::cout << "Hello! Type help for instructions on how to use this utility." << std::endl;
			_input_invitation();
		}
		static void show_message(const std::string& message) {
			std::cout << message << std::endl;
			_input_invitation();
		}
		static void show_help() {
			std::cout << "Help: " << std::endl
				  << "- useradd <username> - add user to the system" << std::endl
			  	  << "- bookadd <bookname> - add book to the system" << std::endl
				  << "- give <username> <bookname> - give the specified book to the specified user" << std::endl
				  << "- return <username> <bookname> - make the specified user return the specified book" << std::endl
				  << "- show debtors - show all debtors" << std::endl
				  << "- show users - show all users" << std::endl
				  << "- show books - show all books" << std::endl
				  << "- quit - quit program" << std::endl;
			_input_invitation();
		}
		static void show_error(const std::string& error) {
			std::cerr << error << std::endl;
			_input_invitation();
		}
};

#endif //CVIEW_HPP
