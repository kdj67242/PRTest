
// ItemType.h
// kdj6724@naver.com
// 2019-07-13
#include <fstream>
const int MAX_ITEMS = 10;
enum RelationType {LESS, GREATER, EQUAL};

class ItemType {
public:
	ItemType();
	RelationType ComapredTo(ItemType& item) const;	
	void Print(std::ofstream&) const;
	void Initialize(int number);
private:
	int value_;	
};
