class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int max2=-1,ct=0;
        for(int i=0;i<arr.size();i++){
            max2=max(max2,arr[i]);
            if(max2==i) ct++;
        }
        return ct;
    }
};
