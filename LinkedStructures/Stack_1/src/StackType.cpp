// StackType.cpp
// 2019-08-03
// kdj6724@naver.com

#include <iostream>
#include "StackType.h"

StackType::StackType() {
	topPtr_ = nullptr;
}

StackType::~StackType() {
	NodeType* tmp;

	while (topPtr_ != nullptr) {
		tmp = topPtr_;
		topPtr_ = topPtr_->next;
		delete tmp;
	}
}

void StackType::Push(ItemType item) {
	if (IsFull()) {
		throw FullStack();
	} else {
		NodeType* location;
		location = new NodeType;
		location->info = item;
		location->next = topPtr_;
		topPtr_ = location;	
	}
}

void StackType::Pop() {
	if (IsEmpty()) {
		throw EmptyStack();
	} else {
		NodeType* tmp;
		tmp = topPtr_;
		topPtr_ = topPtr_->next;
		delete tmp;
	}
}

ItemType StackType::Top() {
	if (IsEmpty()) {
		throw EmptyStack();
	} else {
		return topPtr_->info;
	}
}

bool StackType::IsEmpty() const {
	return (topPtr_ == nullptr);
}

bool StackType::IsFull() const {
	NodeType* location;
	try {
		location = new NodeType;
		delete location;
		return false;
	} catch (std::bad_alloc exception) {
		return true;
	}
}
