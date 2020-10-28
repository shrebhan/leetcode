class Solution {
public:
    bool inrange(char ch)
    {
        if((ch >=65 && ch<=90 )|| (ch >=97 && ch <=122) || (ch >=48 && ch<=57 )) return true;
        return false;
    }
    
    bool casediff(char ch1, char ch2)
    {
        if((((ch1 >=65 && ch1 <=90) && (ch2 >=97 && ch2 <=122))) || (((ch2 >=65 && ch2 <=90) && (ch1 >=97 && ch1 <=122))))
        {
            if(abs(ch1-ch2)==32) return true;
        }
        return false;
    }
    
    bool isPalindrome(string s) {
        if(s.empty() || s.size()==1) return true;
        int n = s.size();
        int i=0, j=n-1;
        while(i<=j)
        {
            while(i<n && !inrange(s[i]))i++;
            while(j>-1 && !inrange(s[j]))j--;
            //cout<<s[i]<<" "<<s[j]<<endl;
            if(i>=n || j<0) break;
            if(s[i]==s[j] || casediff(s[i],s[j]))
            {
                i++;
                j--;
            }
            //cout<<s[i]
            else return false;
        }
        return true;
    }
};