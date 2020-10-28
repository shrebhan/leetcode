class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        
        int j=n-1, k=(m+n)-1;
        for(int i=m-1; (i>-1 && k>-1 && j>-1);)
        {
            if(nums2[j] > nums1[i])
            {
                nums1[k]=nums2[j];
                k--;
                j--;
            }
            else
            {
                nums1[k]=nums1[i];
                i--;
                k--;
                //nums1[k]=nums2[j];
                //j--;
            }
        }
        while(j>-1 && k >-1)
        {
            nums1[k]=nums2[j];
            j--;
            k--;
        }
    }
};