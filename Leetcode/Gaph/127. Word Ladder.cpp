bool check(string str1,string str2){
    int i,j,k;
    i=0;int ct=0;
    for(i=0;i<str1.size();i++){
        if(str1[i]!=str2[i]) ct++;
    }
    if(ct==1) return true;
    else return false;
}
class Solution {
public:
    int ladderLength(string b, string e, vector<string>& w) {
        int i,j,k,n,m,ct=0;
        w.push_back(b);
        n=w.size();
        //for(i=0;i<n;i++) cout<<w[i]<<" ";
        vector<int> adj[n+5];
        int vis[n+5];
        for(i=0;i<n+3;i++) vis[i]=0;
        int flag=0;
        for(i=0;i<n;i++){
            if(w[i]==e) flag=1;
        }
        if(flag==0) return 0;
        for(i=0;i<n;i++){
            for(j=i+1;j<n;j++){
                if(check(w[i],w[j])==true){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        queue<pair<int,int>> bfs;
        bfs.push({n-1,0});vis[n-1]=1;
       while(bfs.empty()==false){
            auto it=bfs.front();
            //cout<<it.first<<" "<<it.second<<endl;
            if(w[it.first]==e) return it.second+1;
            for(auto x:adj[it.first]){
                if(vis[x]==0) {
                    vis[x]=1;
                    if(w[x]==e) return it.second+2;          
                    bfs.push({x,it.second+1});}
            }
            bfs.pop();
        }
        return 0;
    }
};
