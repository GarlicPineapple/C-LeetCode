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
using namespace std;

class PrimaryAlgo
{
public:
	// สýื้
	int removeDuplicates(vector<int>& nums);
	int maxProfit(vector<int>& prices);
	void rotate(vector<int>& nums, int k);
	void rotate_subroutine(vector<int>& nums, int l, int r);
	bool containsDuplicate(vector<int>& nums);
	void containsDuplicate_bubble_sort(vector<int>& nums);
	int singleNumber(vector<int>& nums);
	vector<int> intersect(vector<int>& nums1, vector<int>& nums2);
	vector<int> plusOne(vector<int>& digits);
};

#endif // !_PRIMARYALGO_H_




