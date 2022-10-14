#pragma once
#ifndef _STRUCTURE_H_
#define _STRUCTURE_H_

struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Node {
public:
	int val;
	Node *next;
	Node *rand;
	Node(int x):val(x){}
};// 含随机指针的链表节点

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};// 树节点

class BalanceReturnType {
public:
	int height;
	bool isBalance;
	BalanceReturnType(bool isB, int h):isBalance(isB),height(h){}
};
class Structure
{

};

#endif // !_STRUCTURE_H_