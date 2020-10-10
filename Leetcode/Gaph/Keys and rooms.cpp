class Solution {
public:
        void DFS(vector<int>& visited,int start,vector<vector<int>>& rooms){
              
                
                if(visited[start])
                        return;
                visited[start]=1;
                
                int n=rooms[start].size();   
                for(int k=0;k<n;k++){
                       
                        if(visited[rooms[start][k]]==0)
                                DFS(visited,rooms[start][k],rooms);
                }
                
                
                return;
        }
        
        
        
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
           int n=rooms.size();
      
            vector<int> visited(n,0);
            
            DFS(visited,0,rooms);

            for(int i=0;i<n;i++){
                   
                    if(visited[i]==0)
                            return false;
            }
            return true;
        
    }
};
