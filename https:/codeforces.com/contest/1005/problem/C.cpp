#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll max1 =(ll)1e9;
int main(){
  ll i,j,k,n,m,ct=0,t,ans=0,flag=0;
  cin>>n;
  ll a[31]={0};
  for(i=0;i<31;i++) a[i]=pow(2,i);
  map<ll,ll> dict;
  for(i=0;i<n;i++){
  	cin>>k;
  	if(dict.find(k)!=dict.end()) dict[k]++;
  	else dict.insert({k,1});
  }
  for(auto it=dict.begin();it!=dict.end();it++){
  	ll val=it->first;flag=0;
  	for(i=1;i<31;i++){
  		if(a[i]>val){
  			ll x=a[i]-val;
  			if(dict.find(x)!=dict.end()){
  				if(x==val && dict[x]>1){
				 flag=1;break;}
  				else if(x!=val){
				flag=1;break;}
  				else flag=0;
			  }
			  else flag=0;
		  }
	  }
	  if(flag==0) ct+=dict[val];
	  else flag=0;
  }
  cout<<ct<<endl;
  return 0;
}
