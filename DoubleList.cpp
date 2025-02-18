#include<iostream>
using namespace std;
template <typename T>
struct DoubleList {	
	T val;
	DoubleList<T>* ahead;
	DoubleList<T>* next;
	DoubleList(T n=T()):val(n),ahead(nullptr),next(nullptr){}

};
int main() {
	int num;
	cin >> num;
	DoubleList<int>* head = new DoubleList<int>(num);
	DoubleList<int>* p = head;
	while (cin >> num) {
		DoubleList<int>* q = new DoubleList<int>(num);
		p->next = q;
		q->ahead = p;
		p = p->next;
	}
	if (cin.fail()) {
		cin.clear();
		cin.ignore();
	}
	DoubleList<int>* m = head;
	while (m!=nullptr) {
		cout << m->val << endl;
		m = m->next;
	}
	while (p != nullptr) {
		cout << p->val << endl;
		p = p->ahead;
	}
	return 0;
}
