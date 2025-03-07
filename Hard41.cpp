/*
Given an unsorted integer array nums. Return the smallest positive integer that is not present in nums.

You must implement an algorithm that runs in O(n) time and uses O(1) auxiliary space.
Example 1:

Input: nums = [1,2,0]
Output: 3
Explanation: The numbers in the range [1,2] are all in the array.
Example 2:

Input: nums = [3,4,-1,1]
Output: 2
Explanation: 1 is in the array but 2 is missing.
Example 3:

Input: nums = [7,8,9,11,12]
Output: 1
Explanation: The smallest positive integer 1 is missing.
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool IsNotCondition(int value, int lim) {
    if (value <= 0) return true;
    if (value > lim) return true;
    return false;
}

bool IsCondition(int value, int lim) {
    return !IsNotCondition(value, lim);
}

void SortComponents(vector<int>& nums, int& begin, int& end) {

    while (begin != end)
    {
        //While nums[begin] is >0 and <= nums.size() we moving forward
        //start position
        while (IsCondition(nums[begin], static_cast<int>(nums.size()))) {
            ++begin;
            if (begin == end) { break; }
        }
        //if begin == end there are no reason to work more
        if (begin >= end) { break; }
        
        //If nums[end] Is is >0 and <= nums.size() we swapping with
        //not conditional nums[begin]. If element before end are all
        //valid for our conditional we'll not going through this case.
        if (IsCondition(nums[end], static_cast<int>(nums.size()))) {
            swap(nums[end], nums[begin]);
        }
        //decrement end position while Is not valid nums[end] or beging >= end
        while (IsNotCondition(nums[end], static_cast<int>(nums.size()))) { --end; 
           if (end == 0) { break;}
        }
    };
}

void SortValidPartition(vector<int>& nums, int end) {

    for (int i = 0; i < end; ++i) {
        //If both element are matching to our condition
        if (IsCondition(nums[i], static_cast<int>(nums.size())) &&
            IsCondition(nums[i + 1], static_cast<int>(nums.size())))
        {
           
            while (nums[i] > nums[i + 1]) {
                swap(nums[i], nums[i + 1]);
                //after swapping we must check previos pair ov values
                if (i > 0) { --i; }
            }
        }
        //If nums[i + 1] is !Condition we reached right-side border where are
        //not conditional elements.
        else { break; }
    }
}

int FindMissingInPreparedCollection(const vector<int>& nums) {
    int missed_int = 1;
    for (int i = 0; i < static_cast<int>(nums.size()); ++i) {
       
        if (IsNotCondition(nums[i], static_cast<int>(nums.size()))) {
            //We reached border where values are invalid 
            return ++missed_int;
        }
        else if (nums[i] == missed_int) {
          //in this case nothing, waiting for difference,
        }
        else if (nums[i] - missed_int == 1) { 
          //in this case different is soft , hop was on one step     
            ++missed_int;
        }
        else { 
            //in this case different is large , hop was on more then 
            //one step. ++missed_int is missing     
            return ++missed_int; 
        }
    }
    //If all elements in collection are good we must return 
    // ++laste element in collection
    return ++missed_int;
}

int firstMissingPositiveBad(vector<int>& nums) {
    
    //IF EMPTY OUR ANSWER IS 1
    if (nums.empty()) { return 1;}
    //IF OUR SIZE IS 1 WE MUST CHECK NUMS[0] FOR
    //EQUAL TO 1.
    if (nums.size() == 1) {
        return (nums[0]) == 1 ? 2 : 1;
    }
    
    int begin = 0;
    int end = static_cast<int>(nums.size()) - 1;

    //MOVING VALUES WHICH >0 AND <=N TO LEFT SIDE,
    //AND OTHER TO RIGHT SIDE
    SortComponents(nums, begin, end);
       
    //THE ELEMENTS WHICH ARE VALID MUST ME ORDERED
    SortValidPartition(nums, end);
    
    int missed_int = 1;
    if (nums[0] != missed_int) { return missed_int; }
    
    //FIND NEEDED ANSWER 
    return FindMissingInPreparedCollection(nums);
}

int firstMissingPositiveGood(vector<int>& nums) {

    //IF EMPTY OUR ANSWER IS 1
    if (nums.empty()) { return 1; }
    //IF OUR SIZE IS 1 WE MUST CHECK NUMS[0] FOR
    //EQUAL TO 1.
    if (nums.size() == 1) {
        return (nums[0]) == 1 ? 2 : 1;
    }

    int begin = 0;
    int end = static_cast<int>(nums.size()) - 1;

    //MOVING VALUES WHICH >0 AND <=N TO LEFT SIDE,
    //AND OTHER TO RIGHT SIDE
    auto it_border = partition(nums.begin(), nums.end(), [&nums](int val)
        {return (val > 0) && (val <= nums.size()); });

    //THE ELEMENTS WHICH ARE VALID MUST ME ORDERED
    sort(nums.begin(), it_border);

    int missed_int = 1;
    while (std::binary_search(nums.begin(), it_border, missed_int)) {
        ++missed_int; 
    }
    return missed_int;
}

int main()
{
    vector<int> v1{-500, -4, 5, -50, -3, 1, -3, 2};
    vector<int> v2{-500, -4, 1, -50, -3, -1, -3, -2};    
    vector<int> v3{500, 4, -1,-50 ,-3,1,3, 2};
    vector<int> v4{500, 4, -1, -50, -3, 1, 3, 2,4,2,3,1, 5, 8};
    vector<int> v5{1, 3, 2, 4};

    vector<int> v6{-500, -4, -1, -50, -3, -1, -3, -2};
    vector<int> v7{-4, 1, 3, 1, 3,0, 2, -3};
    vector<int> v8{-4, 1};
    vector<int> v9{1,0};
    cout<< firstMissingPositiveGood(v5);
}


