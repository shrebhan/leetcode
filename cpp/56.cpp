class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;
        if(intervals.empty() || intervals.size()==1) return intervals;
        sort(intervals.begin(), intervals.end(), [](const vector<int>& lhs, const vector<int>& rhs)
             { return lhs[0] < rhs[0]; });
        
        vector<int> intr;
        intr.push_back(intervals[0][0]);
        int maximum = intervals[0][1];
        
        for(int i=1; i<intervals.size();)
        {
            if(maximum > intervals[i][1])
            {
                i++;
            }
            else if(maximum >= intervals[i][0])
            {
                maximum = intervals[i][1];
                i++;
            }
            else
            {
                intr.push_back(maximum);
                res.push_back(intr);
                intr.clear();
                intr.push_back(intervals[i][0]);
                maximum = intervals[i][1];
                i++;
            }
            if(i==intervals.size() && intr.size()==1)
            {
                intr.push_back(maximum);
                res.push_back(intr);
            }
        }
        return res;
    }
};