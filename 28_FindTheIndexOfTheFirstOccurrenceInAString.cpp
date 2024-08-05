/*
Given two strings needle and haystack, return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.
 */
class Solution {
public:
    int strStr(string haystack, string needle) {
        for(int i = 0; i < haystack.length(); i++){
            if (haystack[i] == needle[0]){
                string s = haystack.substr(i,needle.length());
                if(s == needle){
                    return i;
                }
            }
        }
        return -1;
    }
};