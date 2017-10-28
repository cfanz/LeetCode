/*
 * Write a function to find the longest common prefix string amongst an array of strings.
 *
 */

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int min_len = 0;
        int pos = 0;
        if(strs.size()==0)
            return "";
        if(strs.size()==1)
            return strs[0];
        min_len = strs[0].size();
        for(int i=0;i<strs.size();i++){
            if(min_len > strs[i].size())
                min_len = strs[i].size();
        }
        int i,j;
        bool not_all = false;
        for(i=0;i<min_len;i++){
            for(int j=0;j<strs.size()-1;j++){
                if(strs[j][i]!=strs[j+1][i]){
                    pos = i-1;
                    not_all = true;
                    break;
                }
            }
            if(not_all)
                break;
        }
        cout<< "i="<<i<<",j="<<j<<",pos="<<pos<<endl;
        if(pos<0)
            return "";
        if(pos==0){
            if(not_all)
                return strs[0].substr(0,1);
            return strs[0].substr(0,min_len);
        }
        return strs[0].substr(0,pos+1);
    }
};
/*
 * notes:
 * too much code ...
 */
