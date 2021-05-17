map<string,int> dict;

class Solution {
public:
    int dfs(int i,vector<int> adj[]){
        int ans=0;
        if(adj[i].size()==0) return 1;
        for(auto x:adj[i]){
               ans =max(ans,1+dfs(x,adj));
        }
        return ans;
    }
    int longestStrChain(vector<string>& words) {
        int i,j,k,n=words.size(),m,ct=0;
        dict.clear();
        for(i=0;i<n;i++) dict.insert({words[i],i});
        vector<int> adj[n+1];
        for(auto it=dict.begin();it!=dict.end();it++){
            string str = it->first;
            for(k=0;k<str.size();k++){
                string str2;
                for(j=0;j<str.size();j++){
                    if(j!=k) str2+=str[j];
                }
                auto kt=dict.find(str2);
                if(kt!=dict.end()) adj[kt->second].push_back(it->second);
                str2.clear();
            }
        }
        for(i=0;i<words.size();i++){
            ct = max(ct,dfs(i,adj));
        }
        return ct;
    }
};
