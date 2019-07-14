// CountedQueType.h
// 2019-07-15
// kdj6724@anver.com
#include "QueType.h"

class CountedQueType : public QueType {
public:
	CountedQueType(int max);
	void Enqueue(ItemType item);
	void Dequeue(ItemType& item);
	int LengthIs() const;
private:
	int length_;
};

CountedQueType::CountedQueType(int max) : QueType(max) {
	length_ = 0;
}

void CountedQueType::Enqueue(ItemType item) {
	try {
		QueType::Enqueue(item);
		length_++;
	} catch(FullQueue) {
		throw FullQueue();
	}
}

void CountedQueType::Dequeue(ItemType& item) {
	try {
		QueType::Dequeue(item);
		length_--;
	} catch(EmptyQueue) {
		throw EmptyQueue();
	}
}

int CountedQueType::LengthIs() const {
	return length_;
}

