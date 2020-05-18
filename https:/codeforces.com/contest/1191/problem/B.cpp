//https://codeforces.com/contest/1191/problem/B
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct arr{
	ll first,second;
};
bool comp(struct arr a,struct arr b){
	if(a.first<b.first) return 1;
	else return 0;
}
int main(){
  ll i,j,n,m,ct=0,t,ans=0,ct1=0,min1=3;
  struct arr *dict=(struct arr*)malloc(sizeof(struct arr)*3);
  int k;
  for(i=0;i<3;i++){
  	scanf("%1d",&k);
  	dict[i].first=k;
  	char ch;
  	cin>>ch;
  	if(ch=='s') dict[i].second=0;
  	else if(ch=='m') dict[i].second=1;
  	else dict[i].second=2;}
    sort(dict,dict+3,comp);
	   for(i=0;i<3;i++){
		ct=0,ct1=0;ll ct2=0,flag1=0,flag2=0;
		for(j=i+1;j<3;j++){
			if(dict[i].second==dict[j].second){
				if(dict[i].first==dict[j].first) ct++;
				else if((dict[i].first==dict[j].first-1 && flag1==0)){
					ct1++;flag1=1;
				} 
				else if(dict[i].first==dict[j].first-2 && flag2==0){
					ct2++;flag2=1;
				}
		}
		}
		ct=max(ct,ct1+ct2);
		min1=min(min1,2-ct);
	}
	cout<<min1<<endl;
  return 0;
}
