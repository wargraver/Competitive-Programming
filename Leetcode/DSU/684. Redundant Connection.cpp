class DSU{
public:
    int *parent;
    int *rank;
    
    DSU(int size){
        parent = new int[size];
        rank = new int[size];
        
        for(int i = 0 ; i < size ; i++){
            parent[i] = i;
            rank[i] = 0;
        }
    }
    
    int find(int x){
        
        if(parent[x]==x)
        return x;
    
        parent[x] = find(parent[x]);

        return parent[x];
    }
    
    
    bool unions(int x, int y){
        int xref = find(x);
        int yref = find(y);
        
        if(xref == yref) return false;
        
        if(rank[xref] > rank[yref]) parent[yref] = xref;
        else if(rank[yref] > rank[xref]) parent[xref] = yref;
        else {parent[yref] = xref; rank[xref] += 1;}
        
        return true;
        
    }
    
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        DSU dsu(edges.size()+1);
        for(auto edge : edges)
            if(dsu.unions(edge[0] , edge[1]) == false) return edge;
        
        return {};
    }
};
