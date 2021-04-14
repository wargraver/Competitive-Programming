class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int t) {
        int ROW=mat.size();
        int COL=ROW>0 ? mat[0].size() : 0;
        int i=0, j=COL-1;
        while(i<ROW && j>=0) {
            if(mat[i][j] == t)
                return true;
            if(mat[i][j] < t)
                i++;
            else
                j--;
        }
        return false;
    }
};
