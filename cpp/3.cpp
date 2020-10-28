class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        unordered_map <char, int> m;        
        int mlen = 0, len = 0, ind = -1;
        
        for(int i=0; i<s.size(); i++)
        {          
            if(m.find(s[i]) == m.end() || m[s[i]] < ind) //second condition -  if char is present in hash table but it is present before the string started
            {
                m[s[i]] = i;
                len++;
            }
            else if(m[s[i]] > ind)
            {
                mlen = max(mlen, len);
                len = i-m[s[i]];
                ind = m[s[i]]; // to indicate after this new res string begins
                m[s[i]] = i;
            }  
        }       
        return max(mlen, len);
    }
};