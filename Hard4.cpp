/*
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

double FindMedianaInSorted(const vector<int>& vec) {
    
    if (vec.empty()) { return {}; }
    double value_cen = static_cast<double>(vec[vec.size() / 2]);
    if (vec.size() % 2 != 0) { return value_cen;}
    double value_pre_cen = static_cast<double>(vec[(vec.size() / 2) - 1]);    
    double median = (value_cen + value_pre_cen) / 2.0;

    return median;

}

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

    if (nums1.empty()) { return FindMedianaInSorted(nums2);}
    if (nums2.empty()) { return FindMedianaInSorted(nums1);}
    
        int low1 = 0, low2 = 0, high1 = static_cast<int>(nums1.size()) - 1,
        high2 = static_cast<int>(nums2.size()) - 1;

     /*
         Situation 1:
            vector<int>v1{1, 2, 3, 4, 5,6};
            vector<int>v2{-2, -1, 0, 7, 8,9};
         in the end high2 - low2 will be -1
         and low1 will be at position num 2
         and high will be at position num 3
         Total (3-4) + (3-2) will be 0 

         May be one element from one alive collection:
         vector<int>v1{1, 3, 5, 7};
         vector<int>v2{4};
         low1 will be equal high1 , so high1 - low1 
         will be 0;

         vector<int>v1{1, 3, 5, 7};
         vector<int>v2{2, 4, 6, 8};
         low1 will be equal high1 at position 3 and
         low2 will be equal high2 at position 2.
         so (h1- l1) + (h2 - l2) will be 0;
     */
    while (((high1 - low1) + (high2 - low2)) > 0) {

        if (nums1[low1] < nums2[low2]) 
        { 
            if (low1 <= high1) { ++low1;}
        }
        else 
        { 
            if (low2 <= high2) {++low2;}
        }

        if (nums1[high1] > nums2[high2]) {
            if (high1 >= low1 ) { --high1; }
        }
        else 
        { 
            if (high2 >= low2) { --high2; }
        }
    }

    vector<int> med;
    for (int i = low1; i <= high1; ++i) { med.push_back(nums1[i]);}
    for (int i = low2; i <= high2; ++i) { med.push_back(nums2[i]);} 
    /*
    We dont need sort med.size() will be only 1 or 2;
    */
    return FindMedianaInSorted(med);

}

int main()
{
    vector<int>v111{1, 2, 3, 4, 5,6};
    vector<int>v222{-2, -1, 0, 7, 8,9};

    vector<int>v11{1, 3, 5, 7};
    vector<int>v22{2, 4 ,6, 8 ,10 };

    vector<int>v1{1,2,3, 5,6,7,8};
    vector<int>v2{4};
    double m = findMedianSortedArrays(v1, v2);
    cout << m;

}


