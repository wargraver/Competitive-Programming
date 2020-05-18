//orac and modals
//https://codeforces.com/contest/1350/problem/B
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll max1 =(ll)1e9;
int main(){
  ll i,j,k,n,m,ct=0,t,ans=0,flag=0;
  cin>>t;
  while(t--){
  	cin>>n;
  	ll a[n+1]={0},b[n+1];flag=0;
  	b[0]=0;
  	for(i=1;i<=n;i++) b[i]=1;
  	for(i=1;i<=n;i++) cin>>a[i];
  	for(i=(n)/2;i>=2;i--){
  		flag=0;
  		for(j=2*i;j<=n;j+=i){
  			if(a[j]>a[i]){
			  flag=1;
			  b[i]=max(b[j],b[i]);}
		  }
		  if(flag==1) b[i]+=1;
	  }flag=0;
	for(i=2;i<=n;i++){
		if(a[i]>a[1]){
		b[1]=max(b[i],b[1]);flag=1;	
		}
	}
	max1=0;
	if((flag==1)) b[1]+=1;
	for(i=1;i<=n;i++) max1=max(b[i],max1);
	 cout<<max1<<"\n";
  }
  return 0;
}
