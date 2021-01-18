class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int i,j,n,m,ct=0;
        priority_queue<int,vector<int>> pq(nums.begin(),nums.end());
        while(ct!=k){
            int val=pq.top();
            pq.pop();
            ct++;
            if(ct==k) return val;
        }
        return 0;
    }
};
