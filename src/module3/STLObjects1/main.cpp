#include <set>
#include <string>
#include <iostream>

using namespace std;

class CContact {
	string m_name;
	string m_email;
public:
	CContact(const char* name, const char* email)
		: m_name(name), m_email(email) {}
	CContact(const string& name, const string& email)
		: m_name(name), m_email(email) {}
	string GetName() const { return m_name; }
	string GetEmail() const { return m_email; }

	friend bool operator < (const CContact& c1, const CContact& c2) {
		return c1.m_name < c2.m_name;
	}
};


int main() {
	multiset<CContact> contacts;
	contacts.insert(CContact("Phillip", "the_visualizer@yahoo.com"));
	contacts.insert(CContact("Phillip", "symbolicon@live.com"));
	contacts.insert(CContact("Sally", "sasa88@hotmail.com"));

	char name[64];
	cout << "Enter name:";
	cin.getline(name, sizeof(name));
	CContact contact(name, "");

	multiset<CContact>::iterator p = contacts.find(contact);
	if (p != contacts.end()) {
		multiset<CContact>::iterator e = contacts.upper_bound(contact);
		do {
			cout << p->GetName() << ',' << p->GetEmail() << endl;
		} while (++p != e);
	}



	return 0;
}