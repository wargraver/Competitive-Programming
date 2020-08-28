class Solution {
public:
    void rotate(vector<vector<int>>& a) {
        int i,j,k,n,m;
        int col=a[0].size(),row=col;int ct=0,kt=0;;
        for(i=0;i<col;i++){
        for(j=i;j<col;j++){
        k=a[i][j];
        a[i][j]=a[j][i];
        a[j][i]=k;
        } 
        }
        for(i=0;i<col;i++){
        for(j=0;j<col/2;j++){
            k=a[i][j];
            a[i][j]=a[i][col-1-j];
            a[i][col-1-j]=k;
        }}
    }
};
