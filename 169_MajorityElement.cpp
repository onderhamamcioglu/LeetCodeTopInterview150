/*
Given an array nums of size n, return the majority element.

The majority element is the element that appears more than ⌊n / 2⌋ times.
You may assume that the majority element always exists in the array.
 */
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        for(int num : nums){
            int count = 0;
            for (int number : nums){
                if (num == number){
                    count ++;
                }
            }
            if(count > n/2){
                return num;
            }
        }
        return nums[0];
    }
};