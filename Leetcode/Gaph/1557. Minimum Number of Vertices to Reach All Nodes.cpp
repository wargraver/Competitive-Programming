class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        int freq_in[500005]={0};int max1=0;
        for(int i=0;i<edges.size();i++){
            max1=max(max1,max(edges[i][0],edges[i][1]));
            freq_in[edges[i][1]]++;
        }
        vector<int> vect;
        for(int i=0;i<=max1;i++) if(freq_in[i]==0) vect.push_back(i);
        return vect;
    }
};
