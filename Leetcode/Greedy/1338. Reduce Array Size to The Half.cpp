class Solution {
public:
    int minSetSize(vector<int>& arr) {
        int i,j,k,n,m,ct=0;
        int freq[100005]={0};
        n=arr.size();
        for(i=0;i<n;i++) freq[arr[i]]++;
        sort(freq,freq+100005);
        int sum=0;
        for(i=100004;i>=0;i--){
            sum+=freq[i];
            if(sum>=n/2){
                k=i;
                break;
            }
        }
       // cout<<100004-k+1<<endl;
        return 100004-k+1;
    }
};
