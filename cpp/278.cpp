// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        
        int l=1, h=n;
        
        while(l<=h)
        {
            int mid = ((h-l)/2)+l;
            //cout<<mid;
            if(isBadVersion(mid))
            {
                //cout<<"--";
                if(mid > 1 && isBadVersion(mid-1))
                {
                    h=mid-1;
                }
                else return mid;
            }else
            {
                l=mid+1;
            }
        }
        //oops
        return -1;
        
    }
};