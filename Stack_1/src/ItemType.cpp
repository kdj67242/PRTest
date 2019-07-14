// ItemType.cpp
// kdj6724@naver.com
// 2019-07-13
#include "ItemType.h"

ItemType::ItemType() {
	value_ = 0;
}
RelationType ItemType::ComparedTo(ItemType& item) const {
	if (value_ < item.value_)
		return LESS;
	else if (value_ > item.value_)
		return GREATER;
	else
		return EQUAL;
}
void ItemType::Print(std::ofstream& out) const {
	out << value_ << " ";
}

void ItemType::Initialize(int number) {
	value_ = number;
}
