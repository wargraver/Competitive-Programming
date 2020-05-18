//
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll max1 =(ll)1e9;
int main(){
  ll i,j,k,n,m,ct=0,t,ans=0,flag=0;
  cin>>t;
  multimap<int,int> final;
  vector<int> vec[t+1];;
  for(i=1;i<=t;i++){
  	cin>>n;ll sum=0;
  	set<int> dict;
  	for(j=0;j<n;j++){
  		cin>>k;
  		vec[i].push_back(k);
  		sum+=k;
  		dict.insert(k);
	  }
	for(int x:dict) final.insert({sum-x,i});
  }
  auto it=final.begin();
  auto it2=final.begin();
  for(it=final.begin();it!=final.end();it++){
  	j=it->first;it2=it;
    it2++;
    if(it2!=final.end() && it2->first==it->first){
    	flag=1;break;
	}
  }
  if(flag==0) cout<<"NO";
  else{
  	cout<<"YES\n";
  	ll sum=0,sum1=0;
  	for(int x:vec[it->second]) sum+=x;
  	for(int x:vec[it2->second]) sum1+=x;
  	i=1;j=1;
  	for(int x:vec[it->second]){
  		if(x==sum-it->first) break;
  		i++;
	  }
	  for(int x:vec[it2->second]){
  		if(x==sum1-it2->first) break;
  		j++;
	  }
  	cout<<it->second<<" "<<i<<"\n";
  	cout<<it2->second<<" "<<j<<"\n";
  }
  return 0;
}
