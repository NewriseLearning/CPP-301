#include "Stack.h"

#include <iostream>

typedef CStack<double> DoubleStack;
typedef CStack<int, 52> CardStack;

int main() {
	CStack<char,128> stack1;	
	CStack<> stack2;	// CStack<int,256> stack2;
	CStack<double> stack3;
	CStack<const char*> stack4;
	DoubleStack stack5;
	CardStack stack6;
	
	stack1.Push('A');
	stack1.Push('B');
	stack1.Push('C');

	stack2.Push(100);
	stack2.Push(200);
	stack2.Push(300);

	stack3.Push(1.1);
	stack3.Push(2.2);
	stack3.Push(3.3);

	stack4.Push("Hello!");
	stack4.Push("Goodbye!");
	stack4.Push("Sayonara!");

	while (!stack1.Empty()) std::cout << stack1.Pop() << std::endl;
	while (!stack2.Empty()) std::cout << stack2.Pop() << std::endl;
	while (!stack3.Empty()) std::cout << stack3.Pop() << std::endl;
	while (!stack4.Empty()) std::cout << stack4.Pop() << std::endl;

	return 0;
}

