int dp[2005][2005][2];
class Solution {
public:
    int find(vector<int> arr,int val){
        int low=0,high=arr.size()-1,ans=-1;
        while(low<=high){
            int mid = (low+high)/2;
            if(arr[mid]>val){
                ans=mid;
                high = mid-1;
            }
            else low = mid+1;
        }
        return ans;
    }
    int ways(vector<int> arr1,vector<int> arr2,int i,int j,int flag){
       if(i==arr1.size()) return 0;
        else if(j==-1){
            return min(ways(arr1,arr2,i+1,0,0),1+ways(arr1,arr2,i+1,0,1));
        }
        if(dp[i][j][flag]==-1){
            int last_max;
            if(flag==0) last_max = arr1[j];
            else last_max = arr2[j];
            int ind = find(arr2,last_max);
            if(ind==-1){
                if(last_max<arr1[i]) return dp[i][j][flag]=ways(arr1,arr2,i+1,i,0);
                else return dp[i][j][flag]=1e5;
            }
            else{
                if(last_max<arr1[i]){
                    return dp[i][j][flag]=min(1+ways(arr1,arr2,i+1,ind,1),ways(arr1,arr2,i+1,i,0));
                }
                else return  dp[i][j][flag]=1+ways(arr1,arr2,i+1,ind,1);
            }
        }
        else return dp[i][j][flag];
    }
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        int i,j,k,n,m,ct=0;
        n = arr1.size()-1;m=arr2.size()-1;
        for(i=0;i<n+2;i++){
            for(j=0;j<m+2;j++) {dp[i][j][0]=-1;dp[i][j][1]=-1;}
        }
        sort(arr2.begin(),arr2.end());
        k= ways(arr1,arr2,0,-1,0);
        if(k>=1e5) return -1;
        else return k;
    }
};
