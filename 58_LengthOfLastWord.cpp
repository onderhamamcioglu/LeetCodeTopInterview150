/*
Given a string s consisting of words and spaces, return the length of the last word in the string.

A word is a maximal substring consisting of non-space characters only.
*/
class Solution {
public:
    int lengthOfLastWord(string s) {
        int wordLength = 0;
        bool wordEnded = false;
        int i = s.length() - 1;
        if (i == 0){
            return 1;
        }
        while (!wordEnded && i >= 0){
            if(s[i] == ' '){
                i--;
            }
            else{
                wordLength ++;
                i--;
                while (!wordEnded && i >= 0){
                    if(s[i] == ' '){
                        wordEnded = true;
                    }
                    else{
                        wordLength ++;
                        i--;
                    }
                }
            }
        }
        return wordLength;
    }
};