/*
 * Given a string, find the length of the longest substring without repeating characters.
 * Examples:
 * Given "abcabcbb", the answer is "abc", which the length is 3.
 * Given "bbbbb", the answer is "b", with the length of 1.
 * Given "pwwkew", the answer is "wke", with the length of 3. Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
 */

/*
 * Tips:
 * 1. use map instead of set to record current charset
 * 2. clear map carefully
 */

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size()<1)
            return 0;
        int max,first_pos;
        map<char,int> position_map;
        vector<int> len;
        len.push_back(1);
        position_map.insert(std::pair<char,int>(s[0],0));
        max = 1;
        first_pos = 0;

        for(int i=1; i<s.size();i++){
            map<char,int>::iterator it = position_map.find(s[i]);
            if(it == position_map.end()){
                position_map.insert(pair<char,int>(s[i],i));
                len.push_back(len[i-1]+1);
                if(max < len[i])
                    max = len[i];
            } else {
                int p = it->second;
                int dist = i - it->second;
                len.push_back(dist);
                //clear chars before `it`
                for(int j=first_pos; j<it->second; j++)
                    position_map.erase(s[j]);
                first_pos = it->second + 1;
                it->second = i;
            }
        }
        return max;
    }
};
