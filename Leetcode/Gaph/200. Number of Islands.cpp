int n,m;
void dfs(vector<vector<char>>& grid,int i,int j){
     grid[i][j]='0';
     if(i+1!=n && grid[i+1][j]=='1') dfs(grid,i+1,j);
     if(j+1!=m && grid[i][j+1]=='1')  dfs(grid,i,j+1);
     if(i!=0 && grid[i-1][j]=='1' )   dfs(grid,i-1,j);
     if(j!=0 && grid[i][j-1]=='1')    dfs(grid,i,j-1);
}
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int i,j,k,ct=0;
        n=grid.size();m=grid[0].size();
       
        for(i=0;i<n;i++){
            for(j=0;j<m;j++){
                if(grid[i][j]=='1'){
                    dfs(grid,i,j);
                    ct++;
                }
            }
        }
        return ct;
    }
};
