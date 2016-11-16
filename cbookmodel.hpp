#ifndef CBOOKMODEL_HPP
#define CBOOKMODEL_HPP

#include <string>

class CBookModel {
	private:
		std::string m_name;
		bool m_used;
	public:
		CBookModel() = delete;
		CBookModel(const std::string& name) : m_name(name), m_used(false) {}
		std::string get_name() const { return m_name; }
		void taken() { m_used = true; }
		void returned() { m_used = false; }
		bool is_taken() const { return m_used; }
};
#endif //CBOOKMODEL_HPP
