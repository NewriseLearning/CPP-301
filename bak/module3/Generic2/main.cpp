// #include "Stack.h"
#include "my_templates.h"
#include <iostream>

int main1() {
	//CStack<char, 3> s1;	// CStack<char,3> s1;
	//CStack<char, 5> s1b; // CStack<char,5> s1b;
	CStack<char> s1(3);
	CStack<> s2;	// CStack<int,256> s2;
	CStack<double> s3;	// CStack<double, 256> s3;
	CStack<const char*> s4; // CStack<const char *,256> s4;
	s1.Push('A'); s1.Push('B'); s1.Push('C');
	s2.Push(100); s2.Push(200); s2.Push(300);
	s3.Push(1.1); s3.Push(2.2); s3.Push(3.3);
	s4.Push("Hello!"); s4.Push("Goodbye!"); s4.Push("Sayonara!");
	while (!s1.Empty()) std::cout << s1.Pop() << std::endl;
	while (!s2.Empty()) std::cout << s2.Pop() << std::endl;
	while (!s3.Empty()) std::cout << s3.Pop() << std::endl;
	while (!s4.Empty()) std::cout << s4.Pop() << std::endl;

//	DoubleStack s5;	// CStack<double, 256>
//	CardStack s6;	// CStack<int, 52>

	return 0;
}

int main() {
	CStack<int> s1;
	for (int i = 0; i < 5000; i++) s1.Push(i);
	while (!s1.Empty()) std::cout << s1.Pop() << std::endl;
	return 0;
}