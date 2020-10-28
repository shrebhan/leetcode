class Solution {
public:
    bool checkValidString(string s) {
      stack<int> open,star;
      for(int i=0;i<s.length();i++)
      {
          if(s[i] == ')')
          {
              if(!open.empty()) open.pop();
              else if(!star.empty()) star.pop();
              else return false;
          }
          else if(s[i] == '(')   open.push(i);
          else star.push(i);
      }
      while(!open.empty() && !star.empty())
      {
         if(open.top() > star.top()) return false;
         open.pop();
         star.pop();
      }
        return open.empty();
    }
};