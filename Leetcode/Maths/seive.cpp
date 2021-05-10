class Solution {
public:
    //using seive of erasthonenses
    int countPrimes(int n) {
        int isprime[n+5],ct=0;
        long long int i,j,k,m;
        memset(isprime,0,sizeof(isprime));
        for(i=2;i<n;i++){
            if(isprime[i]==0){
                isprime[i]=1;
                ct++;
                for(j=i*i;j<n;j+=i) isprime[j]=2;
            }
            else continue;
        }
       return ct;
    }
};
