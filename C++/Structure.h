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
};// �����ָ�������ڵ�

class TreeNode {
public:
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) :val(x), left(NULL), right(NULL) {};
};// ���ڵ�

class Structure
{

};

#endif // !_STRUCTURE_H_