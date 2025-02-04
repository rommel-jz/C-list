#include<iostream>
#include<vector>
using namespace std;
typedef struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x):val(x),next(nullptr){}

};
//插入节点
void InsertNode(ListNode*& head, int n) {
	ListNode* newNode = new ListNode(n);
	if (head == nullptr) {
		head = newNode;
		return;
	}
	ListNode* a = head;
	while (a->next != nullptr) {
		a = a->next;
	}
	a->next = newNode;
}
//删除节点，需释放节点内存
void DeleNode(ListNode*& head, int n) {
	if (head == nullptr) {
		return;
	}
	if (head->val == n) {
    ListNode* temp=head;
		head = head->next;
    delete temp;//释放在堆上的该节点
	}
	ListNode* p = head;
	while (p->next != nullptr && p->next->val != n) {
		p = p->next;
	}
	if (p->next == nullptr) {
		return;
	}
	else {
    ListNode* temp=p->next;
		p->next = p->next->next;
    delete p->next;//同样释放内存
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
  //检查cin是否进入错误状态，如果进入消除错误状态
	if (cin.fail()) {
		cin.clear();
		cin.ignore();
	}
	ListNode* m = head;
	while (m!=nullptr) {
		cout << m->val << endl;
		m = m->next;
	}
	
	cin >> num;
	InsertNode(head, num);
	m = head;
	while (m != nullptr) {
		cout << m->val << endl;
		m = m->next;
	}
  
  cin >> num;
DeleNode(head, num);
m = head;
while (m != nullptr) {
	cout << m->val << endl;
	m = m->next;
}
	return 0;
}
