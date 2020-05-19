//https://codeforces.com/contest/1131/problem/B

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll inf=(ll)1e18;
ll mod=(ll)1e9+7;
ll max1=(ll)1e9;
ll ways(ll a,ll b,ll c,ll d){
	ll lower=max(c,d);;
	ll upper=min(a,b);
    ll val=upper-lower;
    if(val<0) return 0;
    else return val+1;
}
int main(){
  ll i,j,k,n,m,ct=0,t,ans=1,a,b,c,d,flag=0;
  cin>>t;c=0;d=0;
  for(i=0;i<t;i++){
  	cin>>a>>b;
    if(c!=a || b!=d){
    	ans+=ways(a,b,c,d);
    	if(c==d) ans--;
	}
  	c=a;d=b;
  }
 cout<<ans<<endl;

  return 0;
}

