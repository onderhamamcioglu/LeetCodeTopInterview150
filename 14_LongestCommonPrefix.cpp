/*
Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".
 */
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size() == 0){
            return "";
        }

        // The common prefix of the first and last strings in the sorted array is the common prefix for the whole array.
        // This is because any common prefix would remain unchanged after sorting.
        sort(strs.begin(), strs.end());

        string first = strs[0];
        string last = strs[strs.size() - 1];

        int i = 0;
        while(i < first.size() && i < last.size() && first[i] == last[i]) {
            i++;
        }
        return first.substr(0, i);
    }
};