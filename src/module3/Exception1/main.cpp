#include <exception>
#include <string>
#include <iostream>

#define ASSERT(condition,code,message)	\
	if (!(condition)) throw new my_exception(code,message,__FILE__,__LINE__)

class my_exception : public std::exception {
	int m_code;
	std::string m_file;
	int m_line;
public:
	my_exception(
		int code,
		const char* message,
		const char* file,
		int line) :
			m_code(code),
			std::exception(message),
			m_file(file),
			m_line(line) { }

	int code() const { return m_code; }
	const std::string& file() const { return m_file; }
	int line() const { return m_line; }
};

using namespace std;

int main() {
	try {
		//	throw new exception("throwing C++ exception.");
	//	throw new my_exception(-1, "my custom exception", __FILE__, __LINE__);
		ASSERT(false, -1, "my custom exception");
	}
	catch (my_exception* e) {
		cout << "Code:" << e->code() << endl
			<< "Message:" << e->what() << endl
			<< "File:" << e->file() << endl
			<< "Line:" << e->line() << endl;
		delete e;
	}
	//catch (exception* e) {
	//	cout << "Exception caught:" << e->what() << endl;
	//	//	throw e;
	//	delete e;
	//}
	return 0;
}