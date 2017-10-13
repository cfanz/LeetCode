/*
 * The string "PAYPALISHIRING" is written in a zigzag pattern
 * on a given number of rows like this: (you may want to display 
 * this pattern in a fixed font for better legibility)
 * --------------------
 * P   A   H   N
 * A P L S I I G
 * Y   I   R
 * --------------------
 * And then read line by line: "PAHNAPLSIIGYIR"
 * Write the code that will take a string and make this conversion given a number of rows:
 * string convert(string text, int nRows);
 * convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".
 */
class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1)
        return s;
    const int len = s.size();
    int parts = len/(2*numRows-2);
    if(len % (2*numRows-2) != 0)
        parts++;
    const int part_max_len = 2*numRows - 2;
    string res=s;
    int cnt = 0;
    for(int i=0; i<numRows; i++){
        //calc 'i'th numRows
        int step = 2*(numRows-i)-2;
        if(step == 0)
            step = 2*(numRows-i)-2;
        for(int j=0; j<parts; j++){
            int index = i+j*part_max_len;
            if(index<len){
                res[cnt] = s[index];
                cnt++;
            }
            if(step==0 || step==part_max_len)
                continue;
            index += step;
            if(index<len){
                res[cnt] = s[index];
                cnt++;
            }
        }
    }
    return res;
    }
};
