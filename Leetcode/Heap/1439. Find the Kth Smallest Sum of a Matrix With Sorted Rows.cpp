//https://leetcode.com/problems/find-the-kth-smallest-sum-of-a-matrix-with-sorted-rows/
class Solution {
public:
    int kthSmallest(vector<vector<int>>& mat, int k) {
        priority_queue<int,vector<int>,greater<int>> pq;
        int n = mat.size(),m=mat[0].size(),i,j;
        for(i=0;i<min(k,m);i++) pq.push(mat[0][i]);
        for(i=1;i<n;i++){
            vector<int> vect;
            while(pq.empty()==false){
            int y = pq.top();
            pq.pop();
            for(j=0;j<m;j++){
               // cout<<y+mat[i][j]<<endl;
                vect.push_back(y+mat[i][j]);
            }
            }
            sort(vect.begin(),vect.end());
            int o = vect.size();
           // for(j=0;j<vect.size();j++) cout<<vect[j]<<" ";
            for(j=0;j<min(k,o);j++) pq.push(vect[j]);
        }
        i=0;
        while(pq.empty()==false){
            i=pq.top();
            pq.pop();
        }
        return i;
    }
};
