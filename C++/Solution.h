#pragma once
#ifndef _SOLUTION_H_
#define _SOLUTION_H_

#include "Structure.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <numeric>
#include <unordered_set> 
#include <unordered_map> 
#include <stack>
using namespace std;

class Solution {
public:
	int lengthOfLongestSubstring(string s);  // 3
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2); // 4
	string longestPalindrome(string s); // 5
	int maxArea(vector<int>& height); // 11
	vector<vector<int>> threeSum(vector<int>& nums); // 15
	vector<string> letterCombinations(string digits); // 17
	void letteradd(vector<string>& res, const unordered_map<char, string> &map, const string& digits, int index, string& respart); // 17
	ListNode* removeNthFromEnd(ListNode* head, int n); // 19
	bool isValid(string s); // 20
	ListNode* mergeTwoLists(ListNode* list1, ListNode* list2); // 21
	vector<string> generateParenthesis(int n); // 22
	ListNode* mergeKLists(vector<ListNode*>& lists); // 23
	ListNode* mergeTwoLists23(ListNode *a, ListNode *b); //23分治算法
	ListNode* mergeLists(vector<ListNode*>& lists, int l, int r); // 23分治算法
	void nextPermutation(vector<int>& nums); // 31
	int longestValidParentheses(string s); // 32
	int search(vector<int>& nums, int target); // 33
	void search_33(vector<int>& nums, int l, int r, int& rotating); // 33二分
	vector<int> searchRange(vector<int>& nums, int target); // 34
	vector<vector<int>> combinationSum(vector<int>& candidates, int target); // 39
	void dfs(vector<int>& candidates, int target, vector<vector<int>>& ans, vector<int>& combine, int index); // 39_树的深度搜索
	int trap(vector<int>& height); // 42

	// 贪心
	int findContentChildren(vector<int>& g, vector<int>& s); //455
	int candy(vector<int>& ratings); //135
	int eraseOverlapIntervals(vector<vector<int>>& intervals); //435

	//基础算法-归并
	void Mergesort(vector<int>& arr, int l, int r);
	void Merge(vector<int>& arr, int l, int mid, int r);
	//基础算法-冒泡
	void bubble_sort(vector<int>& arr, int l, int r);

};

#endif // !_SOLUTION_H_