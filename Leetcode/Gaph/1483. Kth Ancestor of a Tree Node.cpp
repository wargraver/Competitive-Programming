class TreeAncestor {
public:
    vector<vector<int>> vect;
    //Storing the pow(2,i)th parent of every node in vect
    TreeAncestor(int n, vector<int>& parent) {
        int i,j,k,m,ct=0;
        vector<int> adj[n];
        //Creating the Graph
        for(i=0;i<n;i++){
            if(parent[i]!=-1) adj[parent[i]].push_back(i);  
        }
        //Storing the Grandparent for every NODE
        for(i=0;i<=n;i++){
            vector<int> temp;
            for(j=0;j<=20;j++) temp.push_back(-1);
            this->vect.push_back(temp);
       }
        queue<int> bfs;
        bfs.push(0);
        //Performing bfs for finding parents
        while(bfs.empty()==false){
            k = bfs.front();
            bfs.pop();
            vector<int> temp;
            temp.push_back(parent[k]);
            j=1;
            for(i=1;i<=20;i++){
                if(temp[i-1]!=-1){
                    temp.push_back(vect[temp[i-1]][j-1]);
                    j++;
                }
                else temp.push_back(-1);
            }
            for(i=0;i<=20;i++) this->vect[k][i] = temp[i];
            for(auto x:adj[k]) bfs.push(x);
        }
    }
    int getKthAncestor(int node, int k) {
        int i,j,n,ct=0;
        vector<int> temp;
        //Getting the set bits form K
        while(k!=0){
            if(k%2!=0) temp.push_back(ct);
            k=k/2;
            ct++;
        }
        reverse(temp.begin(),temp.end());
        i=0;int ans=-1;
        //Finding ith parent of every Node
        while(i!=temp.size()){
            ans = this->vect[node][temp[i]];
            i++;
            if(ans==-1) return -1;
            node = ans;
        }
        return ans;
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */
