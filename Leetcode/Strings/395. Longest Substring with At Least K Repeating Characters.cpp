class Solution {
public:
    int longestSubstring(string s, int k) {
        int i,j,n=s.size(),m,ct=0,max1=0,ans=0;
        map<char,int> dict;
        for(i=0;i<s.size();i++) dict[s[i]]++;
        max1=dict.size();
        for(i=1;i<=max1;i++){
            int start=0,end=0;
            dict.clear();
            while(end<n && start<n){
                if(dict.size()<=i){
                    dict[s[end]]++;
                    end++;
                    if(dict.size()==i){
                        int flag=0;
                        for(auto it=dict.begin();it!=dict.end();it++){
                            if(it->second<k) flag=1;
                        }
                       if(flag==0) {ans=max(ans,end-start);/*cout<<"hello\n";*/}
                    }
                }
                else if(dict.size()>i){
                    dict[s[start]]--;
                    if(dict[s[start]]==0) dict.erase(s[start]);
                    start++;
                }
            }
        }
        return ans;
    }
};
