// main.cpp
// 2019-07-15
// kdj6724@naver.com
#include "QueType.h"
#include "StackType.h"
#include <iostream>

int main() {
	using namespace std;
	bool palindrome = true;
	char character;
	StackType<char> stack;
	QueType<char> queue;
	char stackChar;
	char queChar;
	cout << "Enter a string: press return." << endl;
	cin.get(character);
	while (character != '\n') {
		stack.Push(character);
		queue.Enqueue(character);
		cout << "in : " << character << endl;
		cin.get(character);
	}
	while (palindrome && !queue.IsEmpty()) {
		stackChar = stack.Top();
		stack.Pop();
		queue.Dequeue(queChar);
		cout << "stack : " << stackChar;
		cout << " que : " << queChar << endl;
		if (stackChar != queChar)
			palindrome = false;
	}

	if (palindrome)
		cout << "String is a palindrome" << endl;
	else
		cout << "String is not a palindrome" << endl;

	return 0;
}
