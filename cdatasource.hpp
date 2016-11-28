#ifndef CDATASOURCE_HPP
#define CDATASOURCE_HPP
#include <vector>
#include <string>

class IDataSource {
	public:
		virtual void load_data(std::vector<std::string>& output) = 0;
};

class CDataSourceFirst : public IDataSource {
	public:
		virtual void load_data(std::vector<std::string>& output) {
			output.reserve(3);
			output.push_back("first_book_first_source");
			output.push_back("second_book_first_source");
			output.push_back("third_book_first_source");
		}
};

class CDataSourceSecond : public IDataSource {
	public:
		virtual void load_data(std::vector<std::string>& output) {
			output.reserve(3);
			output.push_back("first_book_second_source");
			output.push_back("second_book_second_source");
			output.push_back("third_book_second_source");
		}
};

class CDataSourceThird : public IDataSource {
	public:
		virtual void load_data(std::vector<std::string>& output) {
			output.reserve(3);
			output.push_back("first_book_third_source");
			output.push_back("second_book_third_source");
			output.push_back("third_book_third_source");
		}
};
#endif //CDATASOURCE_HPP
