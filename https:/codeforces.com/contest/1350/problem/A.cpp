//orac and factors
//https://codeforces.com/contest/1350/problem/A

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll max1 =(ll)1e9;
ll calculate(ll n){
	for(int i=2;i<=sqrt(n);i++){
		if(n%i==0){
			return i;
		}
	}
	return n;
}
int main(){
  ll i,j,k,n,m,ct=0,t,ans=0;
  cin>>t;
  while(t--){
  	cin>>n>>k;
  	ll final_val=n;
  	i=0;
  	while(final_val%2!=0){
  		final_val+=calculate(final_val);
  		//cout<<final_val<<endl;
  		i++;
	  }
	cout<<final_val+2*(k-i)<<endl;
  }
  return 0;
}
