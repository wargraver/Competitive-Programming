class Solution {
public:
    int candy(vector<int>& ratings) {
        int i,j,k,n,m,ct=0;
        n=ratings.size();
        int left[n],right[n];
        left[0]=1;
        right[n-1]=1;
        for(i=1;i<n;i++){
            if(ratings[i-1]<ratings[i]) left[i] = left[i-1]+1;
            else left[i]=1;
        }
        for(i=n-2;i>=0;i--){
            if(ratings[i+1]<ratings[i]) right[i]  = right[i+1]+1;
            else right[i] = 1;
        }
        int sum=0;
        for(i=0;i<n;i++){
            sum+=max(left[i],right[i]);
        }
        return sum;
    }
};
