#include <windows.h>
#include "async_obj.h"

class async_msgbox : public async_object<LPCTSTR> {
public:
	async_msgbox(LPCTSTR message) : async_object(message) {}
	void run(LPCTSTR message) override {
		MessageBox(NULL, message, TEXT("Message"), MB_OK);
	}
};


int main() {
	async_msgbox b1(TEXT("Hello!"));
	async_msgbox b2(TEXT("Goodbye!"));
	async_msgbox b3(TEXT("Sayonara!"));

//	MessageBox(NULL, TEXT("Hello!"), TEXT("Message"), MB_OK);
//	MessageBox(NULL, TEXT("Goodbye!"), TEXT("Message"), MB_OK);
//	MessageBox(NULL, TEXT("Sayonara!"), TEXT("Message"), MB_OK);

	b1.wait();
	b2.wait();
	b3.wait();

	return 0;
}