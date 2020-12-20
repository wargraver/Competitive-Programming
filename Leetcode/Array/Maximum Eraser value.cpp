class Solution {
public:
    int maximumUniqueSubarray(vector<int>& a) {
        set<int> dict;
        int n=a.size();
        int pref[10005]={0};
        int ans=0;
        pref[a[0]]=a[0];
        if(n==1) return a[0];
        int i=0,j=1;int sum=a[0];
        dict.insert(a[0]);
        while(i<n && j<n){
            if(dict.find(a[j])==dict.end()){
                dict.insert(a[j]);
                sum+=a[j];
                ans=max(sum,ans);
                j++;
            }
            else{
                sum-=a[i];
                dict.erase(a[i]);
                i++;
            }
        }
        return ans;
    }
};
