/*
 * Given a roman numeral, convert it to an integer.
 * Input is guaranteed to be within the range from 1 to 3999.
 *
 */
class Solution {
public:
    int romanToInt(string s) {
        static map<char,int> map = {{'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000}};
        int res = 0;
        for(int i=0;i<s.size()-1;i++){
            if(map[s[i]]<map[s[i+1]]){
                res += map[s[i+1]] - map[s[i]];
                if(i==s.size()-2)
                    return res;
                i++;
                continue;
            }else{
                res += map[s[i]];
            }
        }
        res += map[s[s.size()-1]];
        return res;
    }
};
/* notes:
 * be careful at the last but one character when it is less than its successor.
