class Solution {
public:
    vector<int> decode(vector<int>& b, int first) {
        int i,j,k,n;
        int m=b.size();
        vector<int> ans;
        ans.push_back(first);
        for(i=0;i<m;i++)
        {
            ans.push_back(first^b[i]);
            first=(first^b[i]);
        }
        return ans;
    }
};
