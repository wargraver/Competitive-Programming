typedef pair<int, pair<int,int>> pi; 
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int i,j,n,m,ct=0,ans;
       priority_queue<pi, vector<pi>, greater<pi> > pq; 
        for(i=0;i<matrix.size();i++){
            pq.push({matrix[i][0],{i,0}});
        }
        ct=0;int flag=0;
        while(flag==0){
            if(ct==k-1){
                flag=1;
                //pq.pop();
                ans= pq.top().first;
            }
            else{//cout<<pq.top().first<<endl;
                m=pq.top().second.first;
                n=pq.top().second.second+1;
                pq.pop();
                
                if(n<matrix.size()) pq.push({matrix[m][n],{m,n}});
                ct++;
            }
        }
        return ans;
    }
};
