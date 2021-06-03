class Solution {
public:
    int maxArea(int h, int w, vector<int>& hor, vector<int>& ver) {
        int i,k,j,n,m,ct=0,ans=0,mod = 1e9+7;
        hor.push_back(0);
        ver.push_back(0);
        sort(hor.begin(),hor.end());
        sort(ver.begin(),ver.end());
        n=hor.size()-1;m=ver.size()-1;
        if(hor[n]!=h) hor.push_back(h);
        if(ver[m]!=w) ver.push_back(w);
        int max_diff=0,max_ans=0;
        for(i=1;i<ver.size();i++) max_diff = max(max_diff,ver[i]-ver[i-1]);
        for(j=1;j<hor.size();j++) max_ans = max(max_ans,(hor[j]-hor[j-1])%mod);
        long long int t = (long long int)max_ans*max_diff;
        return t%mod;
    }
};
