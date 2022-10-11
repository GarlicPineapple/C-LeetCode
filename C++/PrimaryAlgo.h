#pragma once
#ifndef _PRIMARYALGO_H_
#define _PRIMARYALGO_H_
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <numeric>
#include <unordered_set> 
#include <unordered_map> 
#include <stack>
#include <regex> // 正则匹配
#include "Structure.h"
using namespace std;

class PrimaryAlgo
{
public:
	// 数组
	int removeDuplicates(vector<int>& nums);
	int maxProfit(vector<int>& prices);
	void rotate(vector<int>& nums, int k);
	void rotate_subroutine(vector<int>& nums, int l, int r);
	bool containsDuplicate(vector<int>& nums);
	void containsDuplicate_bubble_sort(vector<int>& nums);
	int singleNumber(vector<int>& nums);
	vector<int> intersect(vector<int>& nums1, vector<int>& nums2);
	vector<int> plusOne(vector<int>& digits);
	void moveZeroes(vector<int>& nums);
	bool isValidSudoku(vector<vector<char>>& board);
	void rotate(vector<vector<int>>& matrix);
	// 字符串
	void reverseString(vector<char>& s);
	int reverse(int x);
	int firstUniqChar(string s);
	bool isAnagram(string s, string t);
	bool isPalindrome(string s);
	int myAtoi(string s);
	int strStr(string haystack, string needle);
	string countAndSay(int n);
	string countAndSay_recursive(int n);
	string longestCommonPrefix(vector<string>& strs);
	// 链表
	void deleteNode(ListNode* node);
	ListNode* removeNthFromEnd(ListNode* head, int n);
	ListNode* reverseList(ListNode* head);
	ListNode* mergeTwoLists(ListNode* list1, ListNode* list2);
	bool isPalindrome(ListNode* head);
	bool hasCycle(ListNode *head);
	// 树
	int maxDepth(TreeNode* root);
};

#endif // !_PRIMARYALGO_H_




