
class Solution {
public:
    int ways(long long int target,long long int curr,vector<vector<int>> vect,int ind){
        if(ind>=vect.size()){
            if(curr-target>=0) return 0;
            else return 1000;
        }
        else{
            long long int new_target = target-vect[ind][0];
            long long int new_curr = curr-vect[ind][0];
            if(new_target<=0) return 1;
            if(new_curr<0) return 1000; 
            int m = ways(new_target,new_curr,vect,ind+1);
            int n = ways(new_target,new_curr+vect[ind][1],vect,ind+1)+1;
            return min(m,n);
        }
    }
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        int i,j,k,n,m,ct=0;
        n=stations.size();
        for(i=n-1;i>=1;i--)  stations[i][0]=stations[i][0]-stations[i-1][0];
        int ans=ways(target,startFuel,stations,0);
        if(ans>=1e3) return -1;
        else return ans;
     }
};
