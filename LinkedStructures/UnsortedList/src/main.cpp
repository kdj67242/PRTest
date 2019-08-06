 // main.cpp
 // kdj6724@naver.com
 // 2019-07-13

#include <iostream>
#include <fstream>
#include <string>
#include "UnsortedType.h"

void GetData(std::ifstream& dataFile, std::string& item) {
	std::string tmp;
	getline(dataFile, tmp);
	printf("tmp : %s\n", tmp.c_str());
	try {
		item = tmp;
	} catch (std::invalid_argument const &e) {
		std::cout << "Bad input: std::invalid_argument thrown" << '\n';
	} catch (std::out_of_range const &e) {
		std::cout << "Integer overflow: std::out_of_range thrown" << '\n';
	}
}

void PrintList(std::ofstream& dataFile, UnsortedType<std::string> list) {
	int length;
	std::string item;
	list.ResetList();
	length = list.LengthIs();
	printf("len : %d\n", length);
	for (int counter = 1; counter <= length; counter++) {
		list.GetNextItem(item);
		printf("item:%s\n", item.c_str());
	}
}

void CreateListFromFile(std::ifstream& dataFile, UnsortedType<std::string>& list) {
	std::string item;
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
	UnsortedType<std::string> list;
	if (input.fail()) {
		std::cout << "file open error" << std::endl;
		return -1;
	}
	CreateListFromFile(input, list);

	PrintList(output, list);
	
	return 0;
}
