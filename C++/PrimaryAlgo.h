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
#include <regex> // ����ƥ��
using namespace std;

class PrimaryAlgo
{
public:
	// ����
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
	// �ַ���
	void reverseString(vector<char>& s);
	int reverse(int x);
	int firstUniqChar(string s);
	bool isAnagram(string s, string t);
	bool isPalindrome(string s);
	int myAtoi(string s);
	int strStr(string haystack, string needle);
};

#endif // !_PRIMARYALGO_H_




