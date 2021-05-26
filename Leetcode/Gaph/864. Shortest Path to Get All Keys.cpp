class Solution {
public:
    int shortestPathAllKeys(vector<string>& grid) {
        int i,j,k=0,n=grid.size(),m,ct=0,x,y,n2=grid[0].size();
        for(i=0;i<grid.size();i++){
            for(j=0;j<grid[0].size();j++){
                if(grid[i][j]=='@') {x=i;y=j;}
                else if(grid[i][j]-'a'>=0 && grid[i][j]-'a'<26) k++;
            }
        }
        m = pow(2,k)-1;
        queue<tuple<int,int,int,int,int>> q;
        //creating a tuple and pushing x,y,moves,set_bit in the queue.
        q.push({x,y,0,m,m});
        int vis[n][n2][m+1][m+1];
        memset(vis,0,sizeof(vis));
        while(q.empty()==false){
            auto [row,col,moves,set_bit,set_lock] = q.front();
            q.pop();
            if(set_bit==0) return moves;
            else if(vis[row][col][set_bit][set_lock]==1) continue;
            else{
                //cout<<grid[row][col]<<" "<<row<<" "<<col<<endl;
                vis[row][col][set_bit][set_lock]=1;
                if(row-1>=0){
                    int new_val = set_bit,new_lock = set_lock;
                    if(grid[row-1][col]-'a'>=0 && grid[row-1][col]-'a'<26){
                        k=grid[row-1][col]-'a';
                        if((set_bit & 1<<k)==pow(2,k)){
                            new_val = (set_bit xor (1<<k));
                            q.push({row-1,col,moves+1,new_val,new_lock});
                        }
                        else q.push({row-1,col,moves+1,new_val,new_lock});
                    }
                    else if(grid[row-1][col]-'A'>=0 && grid[row-1][col]-'A'<26){
                        k=grid[row-1][col]-'A';
                        if((set_bit & 1<<k)==0){
                        if((set_lock & 1<<k)==pow(2,k)){
                            new_lock= (set_bit xor (1<<k));
                            q.push({row-1,col,moves+1,new_val,new_lock});
                        }
                        else q.push({row-1,col,moves+1,new_val,new_lock});
                        }
                    }
                    else if(grid[row-1][col]!='#') q.push({row-1,col,moves+1,new_val,new_lock});
                }
                 if(row+1<n){
                    int new_val = set_bit,new_lock = set_lock;
                    if(grid[row+1][col]-'a'>=0 && grid[row+1][col]-'a'<26){
                        k=grid[row+1][col]-'a';
                        if((set_bit & 1<<k)==pow(2,k)){
                            new_val = (set_bit xor (1<<k));
                            q.push({row+1,col,moves+1,new_val,new_lock});
                        }
                        else q.push({row+1,col,moves+1,new_val,new_lock});
                    }
                    else if(grid[row+1][col]-'A'>=0 && grid[row+1][col]-'A'<26){
                        k=grid[row+1][col]-'A';
                        if((set_bit & 1<<k)==0){
                        if((set_lock & 1<<k)==pow(2,k)){
                            new_lock= (set_bit xor (1<<k));
                            q.push({row+1,col,moves+1,new_val,new_lock});
                        }
                        else q.push({row+1,col,moves+1,new_val,new_lock});
                        }
                    }
                    else if(grid[row+1][col]!='#') q.push({row+1,col,moves+1,new_val,new_lock});
                }
                if(col-1>=0){
                    int new_val = set_bit,new_lock = set_lock;
                    if(grid[row][col-1]-'a'>=0 && grid[row][col-1]-'a'<26){
                        k=grid[row][col-1]-'a';
                        if((set_bit & 1<<k)==pow(2,k)){
                            new_val = (set_bit xor (1<<k));
                            q.push({row,col-1,moves+1,new_val,new_lock});
                        }
                        else  q.push({row,col-1,moves+1,new_val,new_lock});
                    }
                    else if(grid[row][col-1]-'A'>=0 && grid[row][col-1]-'A'<26){
                        k=grid[row][col-1]-'A';
                        if((set_bit & 1<<k)==0){
                        if((set_lock & 1<<k)==pow(2,k)){
                            new_lock= (set_bit xor (1<<k));
                            q.push({row,col-1,moves+1,new_val,new_lock});
                        }
                            else q.push({row,col-1,moves+1,new_val,new_lock});
                        }
                    }
                    else if(grid[row][col-1]!='#') q.push({row,col-1,moves+1,new_val,new_lock});
                }
               if(col+1<n2){
                    int new_val = set_bit,new_lock = set_lock;
                    if(grid[row][col+1]-'a'>=0 && grid[row][col+1]-'a'<26){
                        k=grid[row][col+1]-'a';
                        if((set_bit & 1<<k)==pow(2,k)){
                            new_val = (set_bit xor (1<<k));
                            q.push({row,col+1,moves+1,new_val,new_lock});
                        }
                        else q.push({row,col+1,moves+1,new_val,new_lock});
                    }
                    else if(grid[row][col+1]-'A'>=0 && grid[row][col+1]-'A'<26){
                        k=grid[row][col+1]-'A';
                        if((set_bit & 1<<k)==0){
                        if((set_lock & 1<<k)==pow(2,k)){
                            new_lock= (set_bit xor (1<<k));
                            q.push({row,col+1,moves+1,new_val,new_lock});
                        }
                            else  q.push({row,col+1,moves+1,new_val,new_lock});
                        }
                    }
                    else if(grid[row][col+1]!='#') q.push({row,col+1,moves+1,new_val,new_lock});
                }
            }
        }
        return -1;
    }
};
