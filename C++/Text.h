#pragma once
#ifndef _TEXT_H_
#define _TEXT_H_

#include "Structure.h"
#include <iostream>
#include <unordered_map> 
#include <stack>
#include <queue>
using namespace std;

class Text
{
public:

	bool fast_solw_pointer(ListNode *head); // 单链表快慢指针回文判断
	//Node* copyListWithRand(Node *head); // 含随机指针的链表拷贝->笔试，哈希表
	//Node copyListWithRand2(Node *head); // 含随机指针的链表拷贝->面试，链表
	ListNode* getLoopNode(ListNode *head); // 判断链表是否有环并返回入环节点，若无环返回null
	ListNode* noLoop(ListNode* head1, ListNode *head2); // 链表无环返回第一个相交节点，，不想交返回null
	ListNode* bothLoop(ListNode* head1, ListNode* loop1, ListNode* head2, ListNode* loop2); // 链表有环返回第一个相交节点，，不相交返回null

	void OrderRecur(TreeNode *head); // 二叉树递归遍历
	void preOrderUnRecur(TreeNode *head); // 二叉树非递归先序遍历
	void inOrderUnRecur(TreeNode *head); // 二叉树非递归中序遍历
	void posOrderUnRecur(TreeNode *head); // 二叉树非递归后序遍历
	int BFS(TreeNode *head);// 二叉树宽度优先遍历并返回树的最大宽度（方法一hashmap，方法二不用hashmap）

	bool isBST(TreeNode* head);// 搜索二叉树判断(方法1递归，方法2非递归)中序遍历
	bool isCBT(TreeNode* head);// 完全二叉树判断
	// 树型DP（动态规划）问题解题思路：从左树、右树获取信息解题
	bool isBalance(TreeNode* head);// 平衡二叉树判断
	BalanceReturnType Balanceprocess(TreeNode* head);// 平衡二叉树递归判断
	TreeNode* LowestCommonAncester(TreeNode *head, TreeNode *o1, TreeNode *o2);// 返回两节点最低公共祖先

};
#endif // !_TEXT_H_



