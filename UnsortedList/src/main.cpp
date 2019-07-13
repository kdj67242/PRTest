 // main.cpp
 // kdj6724@naver.com
 // 2019-07-13

#include <iostream>
#include <fstream>
#include "UnsortedList.h"

void GetData(std::ifstream& dataFile, ItemType& item) {
	std::string tmp;
	getline(dataFile, tmp);
	item.Initialize(std::stoi(tmp));
}

void PrintList(std::ofstream& dataFile, UnsortedType list) {
	int length;
	ItemType item;
	list.ResetList();
	length = list.LengthIs();
	for (int counter = 1; counter <= length; counter++) {
		list.GetNextItem(item);
		item.Print(dataFile);
	}
}

void CreateListFromFile(std::ifstream& dataFile, UnsortedType& list) {
	ItemType item;
	GetData(dataFile, item);
	while (dataFile) {
		if (!list.IsFull())
			list.InsertItem(item);
		GetData(dataFile, item);
	}
}

int main(void) {
	std::ifstream input("input.txt");
	std::ofstream output("output.txt");
	UnsortedType list;
	if (input.fail()) {
		std::cout << "file open error" << std::endl;
		return -1;
	}
	CreateListFromFile(input, list);

	PrintList(output, list);
	
	return 0;
}
