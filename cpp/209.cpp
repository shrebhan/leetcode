class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        if(nums.empty()) return 0;
        int i=0, j=0;
        int min_size = INT_MAX;
        int sum = 0;
        
        while(j<nums.size())
        {
            sum += nums[j];
            while(sum>=s)
            {
                cout<<sum<<" ";
                min_size = min(min_size, (j-i)+1);
                sum -= nums[i];
                i++;
            }
            j++;
            //cout<<min_size<<" ";
        }
        
        return (min_size == INT_MAX) ? 0 : min_size;
    }
};