/*
Given an integer array nums sorted in non-decreasing order, remove the duplicates in-place such that each unique element appears only once.
The relative order of the elements should be kept the same. Then return the number of unique elements in nums.

Consider the number of unique elements of nums to be k, to get accepted, you need to do the following things:

 - Change the array nums such that the first k elements of nums contain the unique elements in the order they were present in nums initially.
   The remaining elements of nums are not important as well as the size of nums.
 - Return k.
 */
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int k = 0; //index of current element and counter of unique elements
        for (const int num : nums)
            if (k < 1 || num != nums[k - 1])
                nums[k++] = num; //next element becomes current element
        return k;
    }
};