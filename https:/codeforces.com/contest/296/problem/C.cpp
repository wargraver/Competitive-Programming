    #include<bits/stdc++.h>
    using namespace std;
    const int maxn=100005;
    int n,m,k;
    long long a[maxn],l[maxn],r[maxn],d[maxn],op[maxn],aux[maxn],x,y;
    int main()
    {
    	cin>>n>>m>>k;
    	for(int i=1;i<=n;i++)
    		cin>>a[i];
    	for(int i=1;i<=m;i++)
    		cin>>l[i]>>r[i]>>d[i];
    	for(int i=1;i<=k;i++)
    		cin>>x>>y,op[x]++,op[y+1]--;
    	for(int i=1;i<=m;i++)
    		op[i]+=op[i-1],aux[l[i]]+=d[i]*op[i],aux[r[i]+1]-=d[i]*op[i];
    	for(int i=1;i<=n;i++)
    		aux[i]+=aux[i-1],cout<<aux[i]+a[i]<<endl;
    	return 0;
    }
