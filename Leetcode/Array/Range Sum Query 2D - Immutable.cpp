class NumMatrix {
public:
    int sum[205][205];
    int r1=0,c2=0;
    NumMatrix(vector<vector<int>>& matrix) {
        int i,j,k,n,m;
        n = matrix.size();
        m = matrix[0].size();
        this->sum[0][0] = matrix[0][0];
        for(i=0;i<n;i++){
            sum[i][0] = 0;
            sum[i][1]=matrix[i][0];
            for(j=1;j<m;j++) this->sum[i][j+1]=(matrix[i][j]+this->sum[i][j]);
        }    
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int ans=0,i,j,k,n,m;
        for(j=row1;j<=row2;j++){
            ans += sum[j][col2+1]-sum[j][col1];
        }
        return ans;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
