class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        set<char> dict;
        int i,j,k,n,m,ct=0,ans=0;
        n=s.size()-1;
        i=0;j=0;
        while(i<=n){
            if(dict.find(s[i])==dict.end()){
                dict.insert(s[i]);
                k=dict.size();
                ans=max(ans,k);
            }
            else{
                while(dict.find(s[i])!=dict.end()) {
                    dict.erase(s[j]);
                    j++;
                }
                dict.insert(s[i]);
                k=dict.size();
                ans=max(ans,k);
            }
            i++;
        }
        return ans;
    }
};
