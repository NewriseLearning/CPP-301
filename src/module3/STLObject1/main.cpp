#include <set>
#include <string>
#include <iostream>

using namespace std;

class CContact {
	string m_name;
	string m_email;
public:
	CContact(const char* name, const char* email) :
		m_name(name), m_email(email) {
	}

	CContact(const string& name, const string& email) :
		m_name(name), m_email(email) {
	}

	const string& GetName() const { return m_name; }
	const string& GetEmail() const { return m_email; }

	friend bool operator < (const CContact & c1, const CContact & c2) {
		return c1.m_name < c2.m_name;
	}
};

//bool operator < (const CContact& c1, const CContact& c2) {
//	return c1.GetName() < c2.GetName();
//}

int main() {
	multiset<CContact> contacts;
	contacts.insert(CContact("Phillip", "symbolicon@live.com"));
	contacts.insert(CContact("Phillip", "xnamp@hotmail.com"));
	contacts.insert(CContact("Sally", "sasa68@hotmail.com"));

	char name[64];
	cout << "Enter name:";
	cin.getline(name, sizeof(name));

	CContact contact(name, "");
	auto p = contacts.find(contact);
	if (p != contacts.end()) {
		auto e = contacts.upper_bound(contact);
		do {
			cout << p->GetName() << ',' << p->GetEmail() << endl;
		} while (++p != e);
	}
	return 0;
}