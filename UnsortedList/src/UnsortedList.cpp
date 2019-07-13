// UnsortedList.cpp
// kdj6724@naver.com
// 2019-07-13

#include "UnsortedList.h"

UnsortedType::UnsortedType() {
	length_ = 0;
	currentPos_ = 0;
}

bool UnsortedType::IsFull() const {
	return (length_ == MAX_ITEMS);
}

int UnsortedType::LengthIs() const {
	return length_;
}

void UnsortedType::RetriveItem(ItemType& item, bool& found) {
	bool moreToSearch;
	int location = 0;
	found = false;
	moreToSearch = (location < length_);
	while (moreToSearch && !found) {
		switch(item.ComapredTo(info_[location])) {
			case LESS:
			case GREATER:
				location++;
				moreToSearch = (location < length_);
				break;
			case EQUAL:
				found = true;
				item = info_[location];
				break;
		}
	}
}

void UnsortedType::InsertItem(ItemType item) {
	info_[length_] = item;
	length_++;
}

void UnsortedType::DeleteItem(ItemType item) {
	int location = 0;
	while (item.ComapredTo(info_[location]) != EQUAL)
		location++;
	info_[location] = info_[length_-1];
	length_--;
}

void UnsortedType::ResetList() {
	currentPos_ = -1;
}

void UnsortedType::GetNextItem(ItemType& item) {
	currentPos_++;
	item = info_[currentPos_];
}
