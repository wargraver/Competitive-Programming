double dp[45][45];
class Solution {
public:
    double dfs(vector<int> adj[],int i,int parent,int k1,int k2,double ans){
        if(i==k2) return (double)ans*dp[parent][i];
        double temp_ans = 0;
        for(auto x:adj[i]){
            if(x==parent && adj[i].size()==1) return 0;
            else if(x==parent) continue;
            if(parent==-1) temp_ans+=dfs(adj,x,i,k1,k2,ans);
            else{ 
            double k4 = (double)ans*dp[parent][i];
            if(parent!=-1) temp_ans+=dfs(adj,x,i,k1,k2,k4);
            }
        }
        return temp_ans;
    }
    void union_1(int k1,int k2,int parent[]){
        int m1 = find_parent(k1,parent);
        int m2 = find_parent(k2,parent);
        if(m1==m2) return;
        parent[m1] = m2;
    }
    int find_parent(int k1,int parent[]){
        while(k1!=parent[k1]){
            k1 = parent[k1];
        }
        return k1;
    }
vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        int i,j,k,n,m,ct=0;
        map<string,int> dict;
        memset(dp,0,sizeof(dp));
        for(i=0;i<equations.size();i++){
            string str1 = equations[i][0];
            string str2 = equations[i][1];
            if(dict.find(str1)==dict.end()){
                dict.insert({str1,ct});
                ct++;
            }
            if(dict.find(str2)==dict.end()) {
                dict.insert({str2,ct});
                ct++;
            }   
        }
        ct = dict.size();
        vector<double> vect;
        vector<int> adj[ct+1];
        int parent[ct+1];
        for(i=0;i<=ct;i++) parent[i]=i;
        for(i=0;i<equations.size();i++){
            auto k1 = dict[equations[i][0]];
            auto k2 = dict[equations[i][1]];
            dp[k1][k2] = (double)values[i];
            dp[k2][k1] = (double)1/values[i];
            //detecting cycle
            if(find_parent(k1,parent)==find_parent(k2,parent)) continue;
            adj[k1].push_back(k2);
            adj[k2].push_back(k1);
            union_1(k1,k2,parent);
        }
        for(j=0;j<queries.size();j++){
        if(dict.find(queries[j][0])==dict.end() ||dict.find(queries[j][1])==dict.end()) {vect.push_back(-1);continue;}
        int k1 = dict[queries[j][0]];
        int k2 = dict[queries[j][1]];
        if(find_parent(k1,parent)!=find_parent(k2,parent)) vect.push_back(-1);
        else{
            if(k1==k2) vect.push_back(1);
           else{
            double m1 =  dfs(adj,k1,-1,k1,k2,1);
           vect.push_back(m1);
               }
        }
        }
    return vect;
    }
};
