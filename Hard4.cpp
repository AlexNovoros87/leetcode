﻿/*
Given two sorted arrays nums1 and nums2 of size m and n 
respectively, return the median of the two sorted arrays.

The overall run time complexity should be O(log (m+n)).
Example 1:

Input: nums1 = [1,3], nums2 = [2]
Output: 2.00000
Explanation: merged array = [1,2,3] and median is 2.
Example 2:

Input: nums1 = [1,2], nums2 = [3,4]
Output: 2.50000
Explanation: merged array = [1,2,3,4] and 
median is (2 + 3) / 2 = 2.5.
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

 // Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
 
  ListNode* mergeKLists(vector<ListNode*>& lists) {

  }

int main()
{
    ListNode* l(5);


}


