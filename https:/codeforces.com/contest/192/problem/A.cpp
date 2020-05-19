#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll inf=(ll)1e18;
ll mod=(ll)1e9+7;
ll max1 =(ll)1e9;
ll gcd(ll a,ll b){
   if(a%b==0) return b;
   else return gcd(b,a%b);
}
int main(){
  ll i,j,k,n,m,ct=0,t,ans=0,flag=0;
  cin>>n;
  set<ll> dict;
  for(i=1;i<=100000;i++) dict.insert(i*(i+1)/2);
  auto it=dict.begin();
  while(*it<n){
  	ll x=*it;
  	ll y=n-x;
  	auto it2=dict.find(y);
  	if(it2!=dict.end()){
  		flag=1;break;
	  }
	else if(2*x==n){
		flag=1;break;
	}
	  it++;
  }
  if(flag==0) cout<<"NO";
  else cout<<"YES";
  return 0;
}

