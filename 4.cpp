//找倒数第K个节点
//原理：通过快慢指针，快指针比慢指针多走k-1
//快：k，慢：1----->快：n，慢：n-k+1；
#include<iostream>
#include<vector>
using namespace std;

typedef struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) :val(x), next(nullptr) {}

};

ListNode* FindKthToTail(ListNode* head, int k) {//核心部分
	ListNode* pHead = head;//
	if (pHead == nullptr || k <= 0) {//
		return nullptr;//
	}//
	for (int i = 0; i < k - 1; i++) {//
		if (pHead->next != nullptr) {//
			pHead = pHead->next;//
		}//
		else {//
			return nullptr;//判断k是否超过链表长度
		}//
	}//
	ListNode* pBehind = head;//
	while (pHead->next != nullptr) {//
		pHead = pHead->next;//
		pBehind = pBehind->next;//
	}//
	return pBehind;//
}//

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

	cin >> num;
	cout << endl << FindKthToTail(head, num)->val << endl;	
	return 0;
}
