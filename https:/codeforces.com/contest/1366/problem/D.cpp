#include<bits/stdc++.h>
using namespace std;
 
int frq[10000007],ans[500005];
 
int main()
{
    int n,x;scanf("%d",&n);
    long long sum;
    for(int i=2; i<10000001; i++){
        for(int j=i; j<10000001; j+=i){
            if(!frq[j])
                frq[j]=i;
        }
    }
    for(int i=0; i<n; i++){
        scanf("%d",&x);
        sum=x;
        while(frq[x]&&sum%frq[x]==0)sum/=frq[x];
        if(sum!=1&&frq[x]){
            printf("%d ",frq[x]);
            ans[i]=sum;
        }else{
             printf("%d ",-1);
             ans[i]=-1;
        }
    }
    printf("\n");
    for(int i=0; i<n; i++)printf("%d ",ans[i]);
}
