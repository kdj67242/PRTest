// QueType.h
// 2019-07-15
// kdj6724@naver.com
#include <iostream>

class FullQueue {
};

class EmptyQueue {
};

typedef char ItemType;
class QueType {
public:
	QueType(int max);
	QueType();
	~QueType();
	void MakeEmpty();
	bool IsEmpty() const;
	bool IsFull() const;
	void Enqueue(ItemType item);
	void Dequeue(ItemType& item);
private:
	int front_;
	int rear_;
	ItemType* items_;
	int maxQue_;
};

QueType::QueType(int max) {
	maxQue_ = max + 1;
	front_ = maxQue_ - 1;
	rear_ = maxQue_ - 1;
	items_ = new ItemType[maxQue_];
}

QueType::QueType() {
	maxQue_ = 501;
	front_ = maxQue_ - 1;
	rear_ = maxQue_ - 1;
	items_ = new ItemType[maxQue_];
}

QueType::~QueType() {
	delete [] items_;
}

void QueType::MakeEmpty() {
	front_ = maxQue_ - 1;
	rear_ = maxQue_ - 1;
}

bool QueType::IsEmpty() const {
	return (rear_ == front_);
}

bool QueType::IsFull() const {
	return ((rear_ + 1) % maxQue_ == front_);
}

void QueType::Enqueue(ItemType item) {
	if (IsFull()) {
		throw FullQueue();
	} else {
		rear_ = (rear_ + 1) % maxQue_;
		items_[rear_] = item;
	}
}

void QueType::Dequeue(ItemType& item) {
	if (IsEmpty()) {
		throw EmptyQueue();
	} else {
		front_ = (front_ + 1) % maxQue_;
		item = items_[front_];
	}
}

