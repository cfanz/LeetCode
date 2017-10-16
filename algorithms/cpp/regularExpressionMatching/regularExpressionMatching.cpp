/*
 * Implement regular expression matching with support for '.' and '*'.
 * '.' Matches any single character.
 * '*' Matches zero or more of the preceding element.
 * The matching should cover the entire input string (not partial).

 * The function prototype should be:
 * bool isMatch(const char *s, const char *p)

 * Some examples:
 * isMatch("aa","a") → false
 * isMatch("aa","aa") → true
 * isMatch("aaa","aa") → false
 * isMatch("aa", "a*") → true
 * isMatch("aa", ".*") → true
 * isMatch("ab", ".*") → true
 * isMatch("aab", "c*a*b") → true
 */

/* THIS IS MY 3.5 HOURS WORK!!! 
 * The standard solution is far more elegant, but i
 * still want to paste my own code here. Maybe i should
 * try to accept the situation: stupid solution, stupid brain,
 * plain life, ha~
 */
class Solution {
public:
void simplify(vector<char> &sm, vector<char> &smt){
    int len=sm.size();
    if(len<2)
        return;
    vector<char> new_sm;
    vector<char> new_smt;
    new_sm.push_back(sm.front());
    new_smt.push_back(smt.front());
    for(int i=1;i<len-1;i++){
        if(sm[i]==sm[i-1] && smt[i]=='*' && smt[i-1]=='*'){
            ;
        }else{
            new_sm.push_back(sm[i]);
            new_smt.push_back(smt[i]);
        }
    }
    if(sm[len-1] == sm[len-2] && smt[len-1]=='*' && smt[len-2]=='*'){
        //dumpliated
        ;
    }else{
        new_sm.push_back(sm[len-1]);
        new_smt.push_back(smt[len-1]);
    }
    sm.swap(new_sm);
    smt.swap(new_smt);
}
   bool foo(string s, vector<char> sm, vector<char> smt, int p, int q){
    //cout<<"p="<<p<<",q="<<q<<endl;
    if(smt[q] != '*'){
        if(s[p] == sm[q] || sm[q] == '.'){
            if(q == sm.size()-1){
                if( p == s.size()-1)
                    return true;
                else
                    return false;
            }
            if(p == s.size()-1){
                for(int i=q+1;i<smt.size();i++){
                    if(smt[i]!='*')
                        return false;
                }
                return true;//all left chars in sm are type '*'
            }
            return foo(s,sm,smt,p+1,q+1);
        }
        else{
                return false;
        }
    }else{
        if(s[p] == sm[q] || sm[q] == '.'){
            if(q == sm.size()-1){
                if( p == s.size()-1)
                    return true;
                else{
                    if (sm[q] == '.')
                        return true;
                    for(int i=p+1;i<s.size();i++)
                        if(s[i]!=s[p])
                            return false;
                    return true;
                }
            }
            if(p == s.size()-1){
                int i = q+1;
                for(;i<smt.size()-1;i++){
                    if(smt[i]!='*')
                        return false;
                }
                if(smt[i] == '*' || sm[i] == '.' || sm[i] == s[p])
                    return true;
                return false;
            }
            return foo(s,sm,smt,p+1,q) ||
                   foo(s,sm,smt,p+1,q+1)||
                   foo(s,sm,smt,p,q+1);
        }else{
            if(q == sm.size()-1)
                return false;
            return foo(s,sm,smt,p,q+1);
        }
    }
}
    bool isMatch(string s, string p) {
        vector<char> sm;
        vector<char> smt;
        if(p.size()==0){
            if(s.size()==0)
                return true;
            else
                return false;
        }
        for(int i=0;i<p.size()-1;i++){
            sm.push_back(p[i]);
            if(p[i+1]=='*'){
                smt.push_back('*');
                i++;
            }else{
                smt.push_back('0');
            }
        }
        char last = p[p.size()-1];
        if(last != '*'){
            sm.push_back(last);
            smt.push_back('0');
        }
        if(s.size()==0){
            for(int i=0;i<smt.size();i++)
                if(smt[i] != '*')
                    return false;
            return true;
        }
        simplify(sm,smt);
        for(int i=0;i<sm.size();i++)
            cout<<sm[i]<<" ";
        cout<<endl;
        for(int i=0;i<smt.size();i++)
            cout<<smt[i]<<" ";
        cout<<endl;
        return foo(s,sm,smt,0,0);
    }
};
