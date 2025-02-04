//反转链表
#include<iostream>
#include<vector>
using namespace std;

typedef struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) :val(x), next(nullptr) {}

};

void Reverse(ListNode*& head) {
	if (head == nullptr) {
		return;
	}
	ListNode* pre = nullptr;//前一个节点

	while (head != nullptr) {
		ListNode* pnext = head->next;		
		head->next = pre;//该节点指向前一个结点
		if (pnext == nullptr) {
			return;
		}
		pre = head;//保存头节点
		head = pnext;//继续到下一个节点进行反转
	}
	
}


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
	if (cin.fail()) {
		cin.clear();
		cin.ignore();
	}

	ListNode* m = head;
	while (m != nullptr) {
		cout << m->val << endl;
		m = m->next;
	}

	Reverse(head);
	m = head;
	while (m != nullptr) {
		cout << m->val << endl;
		m = m->next;
	}

	return 0;
}
