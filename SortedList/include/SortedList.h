 // SortedList.h
 // kdj6724@naver.com
 // 2019-07-13
#include "ItemType.h"

class SortedType {
public:
	SortedType();
	bool IsFull() const;
	int LengthIs() const;
	void RetriveItem(ItemType& item, bool& found);
	void InsertItem(ItemType item);
	void DeleteItem(ItemType item);
	void ResetList();
	void GetNextItem(ItemType& item);
private:
	int length_;
	ItemType info_[MAX_ITEMS];
	int currentPos_;
};
