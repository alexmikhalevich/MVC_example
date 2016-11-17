#ifndef CDATASOURCE_HPP
#define CDATASOURCE_HPP
#include <vector>
#include <string>

class IDataSource {
	public:
		virtual void load_data(std::vector<std::string>>& output) = 0;
};

class CDataSourceFirst : public IDataSource {
	public:
		virtual void load_data(std::vector<std::string>>& output) {}
}

class CDataSourceSecond : public IDataSource {
	public:
		virtual void load_data(std::vector<std::string>>& output) {}
}

class CDataSourceThird : public IDataSource {
	public:
		virtual void load_data(std::vector<std::string>>& output) {}
}
#endif //CDATASOURCE_HPP
