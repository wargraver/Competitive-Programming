class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        int i,j,n,ct=0;
        n=(int)arr.size();
        int freq[100005]={0};
        for(i=0;i<n;i++){
            int mod1=(arr[i]%k+k)%k;
            freq[mod1]++;
        }
        for(i=0;i<k;i++){
            int val1=i;
            int val2=(k-i)%k;
            if(val1==val2){
                if(freq[i]%2!=0) return false; 
            }
            else if(freq[val1]!=freq[val2]) return false;
        }
        return true;
    }
};
