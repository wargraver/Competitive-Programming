#include<bits/stdc++.h>
using namespace std;
typedef long long ll;;
ll inf=(ll)1e18;
ll mod=(ll)1e9+7;
ll max1 =(ll)1e9;
int main(){
  ll i,j,k,n,m,ct=0,t,ans=0,l;
  cin>>n>>m>>k;
	int sum=0;
	int now=1;
	ll a[m+1];
	for(i=1;i<=m;i++) cin>>a[i];
	while(now<=m)
	{
		ll r=((a[now]-sum-1)/k+1)*k+sum;
		while(now<=m&&a[now]<=r)
		{
			sum++;
			now++;
		}
		ans++;
	}
  cout<<ans<<endl;
  return 0;}
----------------------------------------------------------------------------------------------------------------------------------
/*to obtain the total discare value we calculate the righmost element of given element than we add the toal moves in linear time complexity. 
