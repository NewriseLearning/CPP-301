#include <exception>
#include <iostream>

using namespace std;

// C++ SEH : Structured Exception Handling

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
		std::exception(message),
		m_code(code),
		m_file(file),
		m_line(line) {
	}

	int code() const { return m_code; }
	const std::string& file() const { return m_file; }
	int line() const { return m_line; }
};

int main() {
	try {
	//	throw my_exception(101, "Error message.", __FILE__, __LINE__);
		throw new my_exception(101, "Error message.", __FILE__, __LINE__);
	}
	catch (my_exception *e) {
		cout << "Error Code:" << e->code() << endl;
		cout << "Message:" << e->what() << endl;
		cout << "File:" << e->file() << endl;
		cout << "Line:" << e->line() << endl;
	//	throw e;
		delete e;
	}
	catch (my_exception& e) {
		cout << "Error Code:" << e.code() << endl;
		cout << "Message:" << e.what() << endl;
		cout << "File:" << e.file() << endl;
		cout << "Line:" << e.line() << endl;
	}
	catch (exception& e) {
		cout << "Message:" << e.what() << endl;
	}
	return 0;
}