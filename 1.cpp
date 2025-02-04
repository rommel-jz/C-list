//链表的简单例子
#include<iostream>
#include<vector>
using namespace std;
typedef struct ListNode {
	int val;
	ListNode* next;//指向下一个节点
	ListNode(int x):val(x),next(nullptr){}

};
int main() {
	int num;
	cin >> num;
	ListNode* head = new ListNode(num);
	ListNode* p = head;
	while (cin >> num) {
		ListNode* q = new ListNode(num);
		p->next = q;
		p = p->next;
	}
	//在堆上分配储存空间给链表
	if (cin.fail()) {
	cin.clear();
	cin.ignore();
}//检查并清楚错误状态
	ListNode* m = head;
	while (m!=nullptr) {
		cout << m->val << endl;
		m = m->next;
	}
	return 0;
}
