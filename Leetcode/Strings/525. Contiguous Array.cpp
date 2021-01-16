class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int i,j,k,n,m,ct=0;
        n=nums.size();
        int val=0;int pref[n+2];
        if(n==1) return 0;
        pref[0]=0;
        for(i=1;i<=n;i++){
            if(nums[i-1]==0) val--;
            else val++;
            pref[i]=val;
        }
        map<int,int> dict;
        dict.insert({0,0});
        for(i=1;i<=n;i++) dict[pref[i]]=i;
        //for(auto it=dict.begin();it!=dict.end();it++) cout<<it->first<<" "<<it->second<<endl;
        int len=0;
        for(i=0;i<=n;i++){
            auto it=dict.find(pref[i]);
            if(it!=dict.end()){
                int val=it->second-i;
                len=max(len,val);
                if(it->second==i) dict.erase(it);
            }
        }
        return len;
    }
};
