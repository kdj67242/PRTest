// UnsortedList.cpp
// kdj6724@naver.com
// 2019-07-13

#include "SortedList.h"

SortedType::SortedType() {
	length_ = 0;
	currentPos_ = 0;
}

bool SortedType::IsFull() const {
	return (length_ == MAX_ITEMS);
}

int SortedType::LengthIs() const {
	return length_;
}

void SortedType::RetriveItem(ItemType& item, bool& found) {
	int midPoint;
	int first = 0;
	int last = length_ - 1;
	
	bool moreToSearch = first <= last;
	found = false;
	while (moreToSearch && !found) {
		midPoint = (first + last) / 2;
		switch (item.ComparedTo(info_[midPoint])) {
			case LESS:
				last = midPoint - 1;
				moreToSearch = first <= last;
			case GREATER:
				first = midPoint + 1;
				moreToSearch = first <= last;
			case EQUAL:
				found = true;
				item = info_[midPoint];
				break;
		}
	}
}

void SortedType::InsertItem(ItemType item) {
	bool moreToSearch;
	int location = 0;
	moreToSearch = (location < length_);
	while(moreToSearch) {
		switch(item.ComparedTo(info_[location])) {
			case LESS:
			case EQUAL:
				moreToSearch = false;
				break;
			case GREATER:
				location++;
				moreToSearch = (location < length_);
				break;
		}
	}
	for (int i=length_; i>location; i--)
		info_[i] = info_[i - 1];
	info_[location] = item;
	length_++;
}

void SortedType::DeleteItem(ItemType item) {
	int location = 0;
	while (item.ComparedTo(info_[location]) != EQUAL)
		location++;
	for (int i=location+1; i<length_; i++)
		info_[i - 1] = info_[i];
}

void SortedType::ResetList() {
	currentPos_ = -1;
}

void SortedType::GetNextItem(ItemType& item) {
	currentPos_++;
	item = info_[currentPos_];
}
