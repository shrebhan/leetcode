class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        
        if(strs.empty()) return "";
        string res = "";
        char intr = NULL;
        bool flag = true;
        int len = INT_MAX;
        for(string str : strs)
        {
            if(str.size() < len) len = str.size();
        }
        
        for(int i = 0; i < len ;i++)
        {
            for(string str : strs)
            {
                if(intr == NULL)
                {
                    intr = str[i];
                }
                else
                {
                    if(intr != str[i])
                    {
                        flag = false;
                        break;
                    }
                }
            }
            if(flag)
            {
                res += intr;
            }
            else
            {
                return res;
            }
            intr = NULL;
        }
        return res;
    }
};