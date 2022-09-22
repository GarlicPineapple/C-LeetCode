// C.cpp: 定义控制台应用程序的入口点。
//测试222


#include "stdafx.h"
#include "Solution.h"
#include "Text.h"
#include "PrimaryAlgo.h"
#include "Structure.h"
#include <iostream>
#include <exception>
#include <stdexcept>
#include <string>
using namespace std;

int main()
{
	Solution solution;
	//Text text1;
	PrimaryAlgo p;
	vector<int> g = { 1,2,2,1 };
	vector<int> gg = { 2,2 };
	vector<int> res = p.intersect(g, gg);
	for (int s : res) {
		cout << s << endl;
	}
	//cout << p.intersect(g, gg) << endl;
	//solution.search(g, 3);
	//solution.nextPermutation(g);

	/*string s = "bb";
	ListNode *head1 = new ListNode(1);
	ListNode *node1 = new ListNode(4);
	ListNode *node12 = new ListNode(5);
	head1->next = node1;
	node1->next = node12;

	ListNode *head2 = new ListNode(1);
	ListNode *node2 = new ListNode(3);
	ListNode *node22 = new ListNode(4);
	head2->next = node2;
	node2->next = node22;

	ListNode *head3 = new ListNode(2);
	ListNode *node3 = new ListNode(6);
	head3->next = node3;

	vector<ListNode*> lists = { {head1}, {head2}, {head3} };
	ListNode *res = solution.mergeKLists(lists);
	while (res != NULL) {
		cout << res->val << "->";
		res = res->next;
	}*/


	/*// 链表输入
	ListNode *head = NULL;
	ListNode *p = NULL;
	int count,val;
	cout << "输入node个数：";
	cin >> count;
	for (int i = 0; i < count; i++) {
		cout << "第" << i << "个node为：";
		cin >> val;
		if (i == 0) {
			head = new ListNode(val);
			p = head;
		}
		else {
			ListNode *node = new ListNode(val);
			p->next = node;
			p = node;
		}
	}
	// 打印链表
	p = head;
	while (p != NULL) {
		cout << p->val << "->";
		p = p->next;
	}
	bool a=text1.fast_solw_pointer(head);
	cout << "\na = " << a << endl;*/

	/*//含随机指针的链表初始化
	Node *p0 = new Node(0);
	Node *p1 = new Node(1);
	Node *p2 = new Node(2);
	p0->next = p1;	p0->rand = p2;
	p1->next = p2;	p1->rand = p0;
	Node *res = text1.copyListWithRand(p0);
	while (res != NULL) {
		cout << "res val" << res->val << endl;
		res = res->next;
	}*/

	/*// 循环链表初始化
	ListNode *headLoop = new ListNode(0);
	ListNode *head = new ListNode(0);
	ListNode *p = head;
	ListNode *pl = headLoop;
	for (int i = 0; i < 6; i++) {
		ListNode *nl = new ListNode(i);
		ListNode *n = new ListNode(i);
		pl->next = nl;
		p->next = n;
		pl = pl->next;
		p = p->next;
	}
	pl->next = headLoop->next->next->next;
	cout << "res:" << text1.getLoopNode(headLoop)->val << endl;
	cout << "nores:" << text1.getLoopNode(head)->val << endl;*/

	// 树
	

	system("pause");
    return 0;
}

