class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int i,j,n,m,ct=0,t;vector<int> vect;
        n=nums.size();
        deque<int> d;
        for(i=0;i<k;i++){
            while(d.empty()==false && nums[d.back()]<=nums[i]) d.pop_back();
            d.push_back(i);
        }
        for(i=k;i<=n;i++){
           vect.push_back(nums[d.front()]);
            if(i==n) break;
            if(i-d.front()==k) d.pop_front();
             while(d.empty()==false && nums[d.back()]<=nums[i]) d.pop_back();
           d.push_back(i);
        }
        return vect;
    }
};
