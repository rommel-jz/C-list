//list双向链表插入与删除
#include<iostream>
#include<list>
using namespace std;
int main() {
	list<int>MyList = { 10,20,30,40,50 };
  //迭代器插入与删除
	auto it = MyList.begin();//指向第一个元素
	advance(it, 2);//前进2个单位，指向第三个单位
	MyList.insert(it, 5);//“10，20，5，30，40，50”
	for (const auto& b : MyList) {
		cout << b << endl;
	}
  //现在it还是指向原来的第三个元素，即现在第四个元素
	it = MyList.begin();//重新获取迭代器
	advance(it, 3);//指向第四个元素

	MyList.erase(it);//“10，20，5，40，50”
	for (const auto& a : MyList) {
		cout << a << endl;
	}
	MyList.remove(20);//清除链表中所有20的节点
	for (const auto& a : MyList) {
		cout << a << endl;
	}
	MyList.clear();//清空链表
	return 0;
}
