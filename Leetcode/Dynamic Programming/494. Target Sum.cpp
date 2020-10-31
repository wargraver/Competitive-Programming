int t,n;
int a[21];
map<pair<int,int>,int> dict;
int ways(int i,int ans){
    if(i==n){
        if(ans==t) return dict[{i,ans}]=1;
        else return dict[{i,ans}]=0;
    }
    else if(dict[{i,ans}]==-1){
        return dict[{i,ans}]=ways(i+1,ans+a[i])+ways(i+1,ans-a[i]);
    }
    else return dict[{i,ans}];
}
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        ios_base::sync_with_stdio(false);
	cin.tie(NULL);
        int i,j,m;
        t=S;
        int sum=0;
        for(i=0;i<nums.size();i++) sum+=nums[i];
        n=nums.size();
       // dict.clear();
       // a.clear();
        for(i=0;i<nums.size();i++) a[i]=nums[i];
        for(int i=0;i<=nums.size();i++){
            for(int j=-sum;j<=sum;j++) dict[{i,j}]=-1;
        }
        return ways(0,0);
    }
};
