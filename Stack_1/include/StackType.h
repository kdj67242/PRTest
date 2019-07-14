// StackType.h
// 2019-07-14
// kdj6724@naver.com
//#include "ItemType.h"

typedef char ItemType;
const int MAX_ITEMS = 10;

class FullStack {
};

class EmptyStack {
};

class StackType {
public:
	StackType();
	bool IsEmpty() const;
	bool IsFull() const;
	void Push(ItemType item);
	void Pop();
	ItemType Top() const;
private:
	int top_;
	ItemType items_[MAX_ITEMS];
};
