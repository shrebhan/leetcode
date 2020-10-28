class Solution {
public:
    string removeKdigits(string num, int k) {
       string ans = "";                                         
       
       for (char ch : num) {
           while (ans.length() && ans.back() > ch && k) {
               ans.pop_back();                                  
               k--;                                             
           }
           
           if (ans.length() || ch != '0') { ans.push_back(ch); }  
       }
       
       while (ans.length() && k--) { ans.pop_back(); }          
       
       return ans.empty() ? "0" : ans;
}
};