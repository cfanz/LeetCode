/*
 * Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.
 */
class Solution {
public:
    string longestPalindrome(string s) {
            int len=s.size();
    int i=0,j=0;
    int start=0,max=0;
    int p[len][len];
    for(i=0;i<len;i++)
        for(j=0;j<len;j++)
            p[i][j]=-1;
    for(i=0;i<len;i++)
        p[i][i]=1;
    max=1;
    for(i=0;i<len-1;i++)
        if(s[i]==s[i+1]){
            p[i][i+1]=1;
            max=2;
            start=i;
        }
        else
            p[i][i+1]=0;
    for(j=2;j<len;j++){
        for(i=0;i<len-j;i++){
                if(p[i+1][i+j-1]==-1)
                    cout<<"error,"<<i<<","<<j<<endl;
                if(0==p[i+1][i+j-1])
                    p[i][i+j]=0;
                else if(s[i]==s[i+j]) {
                    p[i][i+j]=1;
                    if(max<j+1){
                        start=i;
                        max=j+1;
                    }
                }
                else
                    p[i][i+j]=0;
        }
    }
    return s.substr(start,max);

    }
};
