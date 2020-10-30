typedef int ll;
class Solution {
public:
    int findIntegers(int num) {
     int a[32]={0};
     a[0]=1;a[1]=2;
     for(int i=2;i<=30;i++) a[i]=a[i-1]+a[i-2];
     int i,prev_bit;
     i=30;prev_bit=0;int ans=0;
     while(i>=0){
         if((num & 1<<i)!=0){
              ans+=a[i];
             if(prev_bit==1){
                 ans--;
                 break;
             }
             prev_bit=1;
         }
         else prev_bit=0;
         i--;
     }
        return ans+1;
    }
};
