    //https://codeforces.com/contest/580/problem/B
    
    #include<bits/stdc++.h>
    using namespace std;
    typedef long long ll;
    struct arr{
    	ll first,second;
    };
    bool comp(struct arr c,struct arr d){
    	if(c.first<d.first) return 1;
    	else return 0;
    }
    ll inf=(ll)1e18;
    ll mod=(ll)1e9+7;
    //ll max1 =(ll)1e9;
    int main(){
      ll i,j,k,n,m,ct=0,t,ans=0,d;
      cin>>n>>d;
      struct arr *a = (struct arr*)malloc(sizeof(struct arr)*n);
      for(i=0;i<n;i++) cin>>a[i].first>>a[i].second;
      sort(a,a+n,comp);
      i=0;j=0;ll diff=0;ll max1=0;
      while(j<n){
      	while(j<n && a[j].first-a[i].first<d){
      		ans+=a[j].second;
      		j++;
    	  }
    	 max1=max(ans,max1);
    	 ans-=a[i].second;
    	 i++;
      }
      cout<<max1<<endl;
      return 0;
    }
     
