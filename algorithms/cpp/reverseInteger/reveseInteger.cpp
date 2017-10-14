/*
 * Reverse digits of an integer.
 * Example1: x = 123, return 321
 * Example2: x = -123, return -321
 * Note:
 * The input is assumed to be a 32-bit signed integer. 
 * Your function should return 0 when the reversed integer overflows.
 */

class Solution {
public:
    int reverse(int x) {
        bool negative = x < 0? true:false;
        if(negative)
            x = -x;
        uint64_t res = 0;
        int remainder;
        while(x>0){
            remainder = x % 10;
            x /= 10;
            res = res*10 + remainder;
            cout<<"remainder="<<remainder<<",x="<<x<<",res="<<res<<",bits="<<bitset<32>(res)<<endl;
            if(res > 0x7FFFFFFF)
                return 0;
        }
        int r = (int)res;
        if(negative)
            return -r;
        return r;
    }
};
/*
 * another way to judge whether an operation will overflow:
 * if(x > INT_MAX - r) then x+r will overflow
 * if(x > INT_MAX/r) then x*r will overflow
 * but this way costs more time than using a uint64_t
 */
