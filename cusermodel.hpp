#ifndef CUSERMODEL_HPP
#define CUSERMODEL_HPP

#include <vector>
#include <utility>
#include <ctime>
#include <iterator>
#include <cmath>
#include "exception.hpp"
#include "cbookmodel.hpp"

typedef std::vector<std::pair<std::time_t, CBookModel*>> books_t;
typedef std::vector<std::pair<std::time_t, CBookModel*>>::const_iterator books_iter;

class CUserModel {
	private:
		static constexpr unsigned int MAX_BOOKS = 3;
		static constexpr unsigned int MAX_TIME = 2592000; //one month (30 days) in seconds
		books_t m_books;
		std::string m_username;
		unsigned int _time_delta(std::time_t first, std::time_t second) const {
			return std::abs(first - second);
		}
	public:
		CUserModel() = delete;
		CUserModel(const std::string& username) : m_username(username) {
			m_books.reserve(MAX_BOOKS);
		}
		void take_book(CBookModel* book) {
			if(m_books.size() == MAX_BOOKS) throw new ExLimitExceeded;
			std::time_t cur_date = std::time(NULL);
			m_books.push_back(std::make_pair(cur_date, book));
			book->taken();
		}
		void return_book(CBookModel* book) {
			for(books_iter iter = m_books.begin(); iter != m_books.end(); ++iter) {
				if((*iter).second == book) {
					m_books.erase(iter);
					book->returned();
					break;
				}
			}
			if(book->is_taken()) throw new ExNoBook;
		}
		bool has_debt() const {
			for(books_iter iter = m_books.begin(); iter != m_books.end(); ++iter) 
				if(_time_delta((*iter).first, std::time(NULL)) > MAX_TIME) return true;
			return false;
		}
};
#endif //CUSERMODEL_HPP
