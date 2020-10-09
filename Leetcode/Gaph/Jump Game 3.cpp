class Solution {
public:
    
    // run DFS until end is reached
    bool dfs(int node, int& n, vector<int>&arr, vector<bool>&visited)
    {
        // invalid index and so return false
        if(node<0 || node>=n) return false;
        
        // node already visited and so return false
        if(visited[node]) return false;
        
        // node index contains value 0 and so return true
        if(arr[node]==0) return true;
        
        // current node visited
        visited[node] = true;
        
        // run DFS for next two directed edge nodes x+arr[x] and x-arr[x]
        // return their OR result which will be true if any neighbour DFS sequence end in value 0
        return dfs(node+arr[node],n,arr,visited) || dfs(node-arr[node],n,arr,visited);
    }
    
    bool canReach(vector<int>& arr, int start) {
        
        // array size
        int n = arr.size();
        
        // node visit track vector to avoid revisit 
        vector<bool>visited(n,false);
        
        // run DFS from start node or index
        return dfs(start,n,arr,visited);
    }
};
