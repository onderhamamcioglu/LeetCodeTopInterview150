/*
Given an integer array nums, rotate the array to the right by k steps, where k is non-negative.

Example 1:

Input: nums = [1,2,3,4,5,6,7], k = 3
Output: [5,6,7,1,2,3,4]
Explanation:
rotate 1 steps to the right: [7,1,2,3,4,5,6]
rotate 2 steps to the right: [6,7,1,2,3,4,5]
rotate 3 steps to the right: [5,6,7,1,2,3,4]
 */

class Solution {
public:
    /*
    // O(k×n) solution
    void rotate(vector<int>& nums, int k) {
        int size = nums.size();
        int tempVal;
        for (int i = 0; i < k; i ++){
            tempVal = nums[size - 1];
            for(int j = size - 1; j > 0; j --){
                nums[j] = nums[j-1];
            }
            nums[0] = tempVal;
        }
    }
     */

    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;    // In case k is larger than the size of the array
        reverse(nums.begin(), nums.end());    // Step 1: Reverse the entire array
        reverse(nums.begin(), nums.begin() + k);    // Step 2: Reverse the first k elements
        reverse(nums.begin() + k, nums.end());    // Step 3: Reverse the remaining n-k elements
    }
};