#ifndef CCONTROLLER_HPP
#define CCONTROLLER_HPP

#include <map>
#include <utility>
#include <string>
#include <stdexcept>
#include <sstream>
#include "cusermodel.hpp"
#include "cview.hpp"
#include "cdatasource.hpp"

class CController {
	private:
		std::map<std::string, CUserModel*> m_users;
		std::map<std::string, CBookModel*> m_books;
		IDataSource* m_source;
		void _add_book(const std::string& name) {
			m_books.insert(std::make_pair(name, new CBookModel(name)));
		}
		void _add_user(const std::string& name) {
			m_users.insert(std::make_pair(name, new CUserModel(name)));
		}
		void _give_book(const std::string& username, const std::string& bookname) {
			try {
				m_users.at(username)->take_book(m_books.at(bookname));
				CView::show_message("The book " + bookname + " was given to " + username);
			} catch(const std::out_of_range& e) {
				CView::show_error("No such book or user.");
			}
		}
		void _return_book(const std::string& username, const std::string& bookname) {
			try {
				m_users.at(username)->return_book(m_books.at(bookname));
				CView::show_message(username + " returned the " + bookname);
			} catch(const std::out_of_range& e) {
				CView::show_error("No such book or user.");
			}
		}
		void _load_source(IDataSource* source) {
			if(m_source) CView::show_error("You have already chosen one source");
			else {
				m_source = source;
				std::vector<std::string> books;
				m_source->load_data(books);
				for(size_t i = 0; i < books.size(); ++i)
					_add_book(books[i]);
				CView::show_message("Successfuly");
			}
		}
	public:
		CController() : m_source(NULL) { CView::show_greeting(); }
		int parse_command(const std::string& input) {
			std::istringstream stream(input);
			std::string tmp;
			stream >> tmp;
			if(tmp == "useradd") {
				stream >> tmp;
				_add_user(tmp);
				CView::show_message("User " + tmp + " added");
			}
			else if(tmp == "bookadd") {
				stream >> tmp;
				_add_book(tmp);
				CView::show_message("Book " + tmp + " added");
			}
			else if(tmp == "give") {
				std::string bookname;
				stream >> tmp >> bookname;
				_give_book(tmp, bookname);
			}
			else if(tmp == "return") {
				std::string bookname;
				stream >> tmp >> bookname;
				_return_book(tmp, bookname);
			}
			else if(tmp == "show") {
				stream >> tmp;
				if(tmp == "debtors") {
					std::string users = "";
					for(auto iter = m_users.begin(); iter != m_users.end(); ++iter)
						if((*iter).second->has_debt()) users += (*iter).first + "\n";
					CView::show_message(users);
				}
				else if(tmp == "users") {
					std::string users = "";
					for(auto iter = m_users.begin(); iter != m_users.end(); ++iter)
						users += (*iter).first + "\n";
					CView::show_message(users);
				}
				else if(tmp == "books") {
					std::string books = "";
					for(auto iter = m_books.begin(); iter != m_books.end(); ++iter)
						books += (*iter).first + "\n";
					CView::show_message(books);
				}
				else throw new ExUnknownCommand;
			}
			else if(tmp == "source") {
				stream >> tmp;
				if(tmp == "1") _load_source(new CDataSourceFirst);
				else if(tmp == "2") _load_source(new CDataSourceSecond);
				else if(tmp == "3") _load_source(new CDataSourceThird);
				else throw new ExUnknownSource; 
			}
			else if(tmp == "help") {
				CView::show_help();
			}
			else if(tmp == "quit") {
				return 0;
			}
			else throw new ExUnknownCommand;

			return 1;
		}
		~CController() {
			for(auto iter = m_users.begin(); iter != m_users.end(); ++iter) 
				delete (*iter).second;
			for(auto iter = m_books.begin(); iter != m_books.end(); ++iter) 
				delete (*iter).second;
			delete m_source;
		}
};

#endif //CCONTROLLER_HPP
