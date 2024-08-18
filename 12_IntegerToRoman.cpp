/*
Seven different symbols represent Roman numerals with the following values:

Symbol	Value
I	1
V	5
X	10
L	50
C	100
D	500
M	1000
Roman numerals are formed by appending the conversions of decimal place values from highest to lowest. Converting a decimal place value into a Roman numeral has the following rules:

If the value does not start with 4 or 9, select the symbol of the maximal value that can be subtracted from the input, append that symbol to the result, subtract its value, and convert the remainder to a Roman numeral.
If the value starts with 4 or 9 use the subtractive form representing one symbol subtracted from the following symbol, for example, 4 is 1 (I) less than 5 (V): IV and 9 is 1 (I) less than 10 (X): IX. Only the following subtractive forms are used: 4 (IV), 9 (IX), 40 (XL), 90 (XC), 400 (CD) and 900 (CM).
Only powers of 10 (I, X, C, M) can be appended consecutively at most 3 times to represent multiples of 10. You cannot append 5 (V), 50 (L), or 500 (D) multiple times. If you need to append a symbol 4 times use the subtractive form.
Given an integer, convert it to a Roman numeral.



Example 1:

Input: num = 3749

Output: "MMMDCCXLIX"

Explanation:

3000 = MMM as 1000 (M) + 1000 (M) + 1000 (M)
 700 = DCC as 500 (D) + 100 (C) + 100 (C)
  40 = XL as 10 (X) less of 50 (L)
   9 = IX as 1 (I) less of 10 (X)
Note: 49 is not 1 (I) less of 50 (L) because the conversion is based on decimal places

 */
class Solution {
public:
 string intToRoman(int num) {
  map<int, string> valueMap;
  valueMap[1] = "I";
  valueMap[4] = "IV";
  valueMap[5] = "V";
  valueMap[9] = "IX";
  valueMap[10] = "X";
  valueMap[40] = "XL";
  valueMap[50] = "L";
  valueMap[90] = "XC";
  valueMap[100] = "C";
  valueMap[400] = "CD";
  valueMap[500] = "D";
  valueMap[900] = "CM";
  valueMap[1000] = "M";

  int digit = 1;
  int last = 0;

  string result;
  while (num != 0) {
   last = num % 10;

   if (last != 0) {
    // Only handle non-zero digits
    if (last < 4) {
     while (last != 0) {
      result.insert(0, valueMap[digit * 1]);
      last--;
     }
    } else if (last == 4) {
     result.insert(0, valueMap[digit * 4]);
    } else if (last == 5) {
     result.insert(0, valueMap[digit * 5]);
    } else if (last > 5 && last < 9) {
     while (last > 5) {
      result.insert(0, valueMap[digit * 1]);
      last--;
     }
     result.insert(0, valueMap[digit * 5]);
    } else if (last == 9) {
     result.insert(0, valueMap[digit * 9]);
    }
   }

   num /= 10;
   digit *= 10;
  }

  return result;
 }
};
