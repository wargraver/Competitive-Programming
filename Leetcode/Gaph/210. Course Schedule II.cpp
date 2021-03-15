class Solution {
public:
    vector<int> findOrder(int num, vector<vector<int>>& prerequisites) {
        int i,j,k,n,m,ct=0;
        vector<int> vect;
        n=num;m=prerequisites.size();
        int indeg[n+1];vector<int> adj[n+1];
        for(i=0;i<=n;i++) indeg[i]=0;
        for(i=0;i<prerequisites.size();i++){
            indeg[prerequisites[i][0]]++;
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        queue<int> q;
        for(i=0;i<=n-1;i++){
            if(indeg[i]==0) q.push(i);
        }
        while(q.empty()==false){
            for(auto x:adj[q.front()]) {
                indeg[x]--;
                if(indeg[x]==0) q.push(x);
            }
            vect.push_back(q.front());
            q.pop();
            ct++;
        }
      if(vect.size()==n) return vect;
      else {
          vect.clear();
          return vect;
      }
    }
};
