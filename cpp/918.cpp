class Solution {
public:
    int maxSubarraySumCircular(vector<int>& A) {
        // 1, -2, 3, -2
        if(A.empty()) return 0;
        int sum = 0, minsum = A[0], s1=0, s2=0;
        int maxsum = A[0];
        
        for(int x : A) sum += x;
        
        for(int i = 0; i<A.size(); i++)
        {
            s1 = max(A[i], s1+A[i]); 
            maxsum = max(maxsum, s1);
            
            s2 = min(A[i], s2+A[i]);
            minsum = min(minsum, s2);
        }
        
        int res = max(maxsum, sum - minsum);
        if(res == 0) res = maxsum;
        
        return res;
        
    }
};