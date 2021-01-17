class Solution {
public:
    int countGoodRectangles(vector<vector<int>>& rect) {
        int i,j,k,n,m,ct=0;
        n=rect.size();
        map<int,int> dict;
        for(i=0;i<n;i++){
            k=min(rect[i][0],rect[i][1]);
            dict[k]++;
        }
        int ans=0;
        auto it=dict.end();
        it--;
        return it->second;;
    }
};
