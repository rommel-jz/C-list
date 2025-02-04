//找到循环链表中的入口节点
#include<iostream>
#include<vector>
using namespace std;

typedef struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) :val(x), next(nullptr) {}

};
//通过设置快节点一次移动两个节点，慢节点移动一个节点找出他们相遇的节点
ListNode* MeetNode(ListNode* head) {
	if (head == nullptr) {
		return nullptr;
	}
	ListNode* SlowNode = head->next;
	ListNode* FastNode = SlowNode->next;
	while (SlowNode != nullptr && FastNode != nullptr) {
		if (SlowNode == FastNode) {
			return FastNode;
		}
		SlowNode = SlowNode->next;
		FastNode = FastNode->next;
		if (FastNode == nullptr) {
			return nullptr;
		}
		FastNode = FastNode->next;
	}
	return nullptr;
}
//从相遇的节点出发继续移动，即回到这个节点，便可计算出循环节点个数
int Count(ListNode* meet) {
	int count = 0;
	ListNode* pNode = meet;
	while (pNode->next != meet) {
		pNode = pNode->next;
		count++;
	}
	count++;
	return count;
}
//前节点先走count个节点，慢节点再走，等他们相遇的节点即为入口节点
ListNode* LoopNode(ListNode* head) {
	ListNode* pMeet = MeetNode(head);
	if (pMeet == nullptr) {
		return nullptr;
	}
	int count = Count(pMeet);
	ListNode* pAhead = head;
	ListNode* pBehind = head;
	for (int i = 0; i < count; i++) {
		pAhead = pAhead->next;
	}
	while (pAhead != pBehind) {
		pAhead = pAhead->next;
		pBehind = pBehind->next;
	}
	return pBehind;
}

int main() {//设计一个循环链表
	ListNode* head = new ListNode(1);
	ListNode* p = head;
	ListNode* pNode = nullptr;
	for (int i = 1; i < 7; i++) {		
		ListNode* Node= new ListNode(i + 1);
		p->next=Node;
		if (i == 5) {			
			pNode = p;			
		}
		p = Node;
		
	}
	p->next = pNode;

	if (MeetNode(head) != nullptr) {
		cout << LoopNode(head)->val << endl;
	}
	else {
		cout << "no loop" << endl;
	}

	
	return 0;
}
