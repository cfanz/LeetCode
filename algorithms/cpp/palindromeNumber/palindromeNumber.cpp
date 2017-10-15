/*
 * Determine whether an integer is a palindrome. Do this without none-constance space.
 */
class Solution {
public:
    int getX(int x,int p){
        while(p>0){
            x/=10;
            p--;
        }
        return x%10;
    }
    bool isPalindrome(int x) {
        if(x==0)
            return true;
        if(x<0){
            return false;
        }
        int len = 0;
        int x2=x;
        while(x2>0){
            x2 /= 10;
            len++;
        }
        for(int i=0;i<len/2;i++){
            if(getX(x,i)!=getX(x,len-i-1))
                return false;
        }
        return true;
    }
};
/*
 * TIPS:
 * reverse half of the number is more elegant
 */
