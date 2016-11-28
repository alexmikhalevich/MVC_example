#ifndef EXCEPTION_HPP
#define EXCEPTION_HPP

#include <string>

class IException {
	public:
		virtual std::string what() const = 0;
};

class ExLimitExceeded : public IException {
	public:
		virtual std::string what() const {
			return "This user has too many books.";
		}
};

class ExNoBook : public IException {
	public:
		virtual std::string what() const {
			return "This user doesn't have such book.";		
		}
};

class ExUnknownCommand : public IException {
	public:
		virtual std::string what() const {
			return "No such command.";
		}
};

class ExUnknownSource : public IException {
	public:
		virtual std::string what() const {
			return "Unknown source.";
		}
};

#endif //EXCEPTION_HPP
