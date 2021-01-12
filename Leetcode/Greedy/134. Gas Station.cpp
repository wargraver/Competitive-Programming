class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int i,j,k,n,m,ct=0;
        n=gas.size();int cal[n];
        for(i=0;i<gas.size();i++){
            cal[i]=gas[i]-cost[i];
            cout<<cal[i]<<" ";
        }
        
        k=-1;int flag=0,prev=0;
        for(i=0;i<n;i++){
            if(flag==0 && cal[i]>=0){
                 flag=1;k=i;
                 prev+=cal[i];
            }
            else if(flag==0 && cal[i]<0) continue;
            else{
                if(prev+cal[i]>=0) prev+=cal[i];
                else{
                    flag=0;
                    prev=0;
                    k=-1;
                }
            }
        }
        if(k!=-1){
            prev=0;
            for(i=k;i<n;i++){
                prev+=cal[i];
                if(prev<0) return -1;
            }
            for(i=0;i<k;i++){
                prev+=cal[i];
                if(prev<0) return -1;
            }
        }
        return k;
    }
};
