/*
 * Given an integer, convert it to a roman numeral.
 * Input is guaranteed to be within the range from 1 to 3999.
 *
 */
class Solution {
public:
    string intToRoman(int num) {
        string unit[9] = {"I","II","III","IV","V","VI","VII","VIII","IX"};
        string decade[9] = {"X","XX","XXX","XL","L","LX","LXX","LXXX","XC"};
        string hundred[9] = {"C","CC","CCC","CD","D","DC","DCC","DCCC","CM"};
        string kilo[9] = {"M","MM","MMM"};
        string res = "";
        int n = num/1000;
        if(n>0){
            num = num % 1000;
            res.append(kilo[n-1]);
        }
        n = num/100;
        if(n>0){
            num = num % 100;
            res.append(hundred[n-1]);
        }
        n = num/10;
        if(n>0){
            num = num % 10;
            res.append(decade[n-1]);
        }
        if(num>0){
            res.append(unit[num-1]);
        }
        return res;
    }
};
