int n,m,l;
bool ways(vector<vector<char>> b,string w,set<pair<int,int>> dict,int i,int j,int ind){
    if(ind==w.size()) return true;
    if(i<0 || j<0 || i>=n || j>=m) return false;
     
    else if(dict.find(make_pair(i,j))==dict.end() && w[ind]==b[i][j]){
          dict.insert(make_pair(i,j));
        return (ways(b,w,dict,i+1,j,ind+1)||ways(b,w,dict,i-1,j,ind+1)||ways(b,w,dict,i,j+1,ind+1)||ways(b,w,dict,i,j-1,ind+1));
    }
    else return false;
}
class Solution {
public:
    bool exist(vector<vector<char>>& b, string w) {
         int i,j,k,ct=0;
         n=b.size(),m=b[0].size();
         l=w.size();
        for(i=0;i<n;i++){
            for(j=0;j<m;j++){
                set<pair<int,int>> dict;
                if(ways(b,w,dict,i,j,0)==true) return true;
            }
        }
        return false;
         
    }
};
