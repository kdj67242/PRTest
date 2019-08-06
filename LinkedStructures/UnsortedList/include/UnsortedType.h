// UnsortedType.h
// 2019-08-06
// kdj6724@naver.com

template <class ItemType>
struct NodeType {
	ItemType info;
	NodeType<ItemType>* next;
};

template <class ItemType>
class UnsortedType {
public:
	UnsortedType();
	~UnsortedType();
	bool IsFull() const;
	int LengthIs() const;
	void MakeEmpty();
	void RetrieveItem(ItemType& item, bool& found);
	void InsertItem(ItemType item);
	void DeleteItem(ItemType item);
	void ResetList();
	void GetNextItem(ItemType& item);
private:
	NodeType<ItemType>* listData_;
	int length_;
	NodeType<ItemType>* currentPos_;
};

template <class ItemType>
UnsortedType<ItemType>::UnsortedType() {
	length_ = 0;
	listData_ = nullptr;
}

template <class ItemType>
UnsortedType<ItemType>::~UnsortedType() {
}

template <class ItemType>
bool UnsortedType<ItemType>::IsFull() const {
	NodeType<ItemType>* location;
	try {
		location = new NodeType<ItemType>;
		delete location;
		return false;	
	} catch (std::bad_alloc exception) {
		return true;
	}
}

template <class ItemType>
int UnsortedType<ItemType>::LengthIs() const {
	return length_;
}

template <class ItemType>
void UnsortedType<ItemType>::MakeEmpty() {
	NodeType<ItemType>* temp;
	while(listData_ != NULL) {
		temp = listData_;
		listData_ = listData_->next;
		delete temp;
	}
	length_ = 0;
}

template <class ItemType>
void UnsortedType<ItemType>::RetrieveItem(ItemType& item, bool& found) {
	bool moreToSearch;
	NodeType<ItemType>* location;
	
	location = listData_;
	found = false;
	moreToSearch = (location != nullptr);
	while (moreToSearch && !found) {
		if (item == location->info) {
			found = true;
			item = location->info;	
		} else {
			location = location->next;
			moreToSearch = (location != nullptr);
		}
	}
}

template <class ItemType>
void UnsortedType<ItemType>::InsertItem(ItemType item) {
	NodeType<ItemType>* location;
	location = new NodeType<ItemType>;
	location->info = item;
	location->next = listData_;
	listData_ = location;
	length_++;
}

template <class ItemType>
void UnsortedType<ItemType>::DeleteItem(ItemType item) {
	NodeType<ItemType>* location;
	NodeType<ItemType>* temp;
	
	location = listData_;
	if (item == location->info) {
		temp = location;
		location = location->next;	
	} else {
		while(!(item == (location->next)->info))
			location = location->next;
		temp = location->next;
		location->next = (location->next)->next;
	}
	delete temp;
	length_--;
}

template <class ItemType>
void UnsortedType<ItemType>::ResetList() {
	currentPos_ = nullptr;
}

template <class ItemType>
void UnsortedType<ItemType>::GetNextItem(ItemType& item) {
	if (currentPos_ == nullptr)
		currentPos_ = listData_;
	else
		currentPos_ = currentPos_->next;
	item = currentPos_->info;
}

