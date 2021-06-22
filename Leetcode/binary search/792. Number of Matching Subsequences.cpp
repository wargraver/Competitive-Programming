class Solution {
public:
    int find(int i,int val,vector<vector<int>> freq){
        int low = 0,high = freq[i].size()-1;
        int ans = -1;
        while(low<=high){
            int mid = (low+high)/2;
            if(freq[i][mid]>val){
                ans=freq[i][mid];
                high = mid-1;
            }
            else low = mid+1;
        }
        return ans;
    }
    int numMatchingSubseq(string s, vector<string>& words) {
         int i,j,k,n,m,ct=0;
         vector<vector<int>> freq(26);
         for(i=0;i<s.size();i++){
             int m = s[i]-'a';
             freq[m].push_back(i);
         }
        ct=0;
        for(i=0;i<words.size();i++){
            int min_ind=-1;int flag=0;
            for(j=0;j<words[i].size();j++){
                k = find(words[i][j]-'a',min_ind,freq);
                if(k==-1){
                    flag=1;
                    break;
                }
                else min_ind = k;
            }
            if(flag==0) ct++;
        }
        return ct;
    }
};
