// StackType.h
// 2019-07-14
// kdj6724@naver.com
//#include "ItemType.h"

const int MAX_ITEMS = 10;

class FullStack {
};

class EmptyStack {
};

template<class ItemType>
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

template<class ItemType>
StackType<ItemType>::StackType() {
  top_ = -1;
}

template<class ItemType>
bool StackType<ItemType>::IsEmpty() const {
  return (top_ == -1);
}

template<class ItemType>
bool StackType<ItemType>::IsFull() const {
  return (top_ == MAX_ITEMS-1);
}

template<class ItemType>
void StackType<ItemType>::Push(ItemType item) {
  if (IsFull())
    throw FullStack();
  top_++;
  items_[top_] = item;
}

template<class ItemType>
void StackType<ItemType>::Pop() {
  if (IsEmpty())
    throw EmptyStack();
  top_--;
}

template<class ItemType>
ItemType StackType<ItemType>::Top() const {
  if (IsEmpty())
    throw EmptyStack();
  return items_[top_];
}
