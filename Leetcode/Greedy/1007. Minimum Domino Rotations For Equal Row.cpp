class Solution {
public:
    int minDominoRotations(vector<int>& a, vector<int>& b) {
        int i,j,k,n,m;n= a.size();
        int freq[7]={0};
        for(i=0;i<n;i++){
            if(a[i]!=b[i]){
                freq[a[i]]++;
                freq[b[i]]++;
            }
            else freq[a[i]]++;
        }
        set<int> dict;
        for(i=1;i<=6;i++){
            if(freq[i]==n) dict.insert(i);
        }
        int ans=1e9;
        if(dict.size()==0) return -1;
        for(auto it=dict.begin();it!=dict.end();it++){
        int val=*it;
            int ct=0,kt=0;
            for(i=0;i<n;i++){
                if(a[i]==b[i] && b[i]==val) continue;
                else if(a[i]==val) ct++;
                else if(b[i]==val) kt++;
            }
            if(ct>=kt){
                 ans=min(ans,kt);
            }
            else ans=min(ans,ct);
        }
        return ans;
    }
};
