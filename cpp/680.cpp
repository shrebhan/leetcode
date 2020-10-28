class Solution {
public:
    bool validPalindrome(string s) {
        int len = s.size();
        int i=0, j=len-1;
        
        while(i<=j)
        {
            if(s[i] == s[j])
            {
                i++;
                j--;
            }
            else
            {
                int i1 = i+1, j1 = j-1;
                while(i1<j && s[i1]==s[j]) {i1++; j--;}
                while(i<j1 && s[i]==s[j1]) {i++; j1--;}
                if(i1<j && i<j1) return false;
                break;
            }
        }
        return true;
    }
};