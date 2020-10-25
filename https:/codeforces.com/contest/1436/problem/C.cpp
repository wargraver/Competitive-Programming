        #include<bits/stdc++.h>
        using namespace std;
        int64_t mod=1e9+7;
        int main () {
        	ios::sync_with_stdio(0);
        	cin.tie(0);
        	int n,x,pos;
        	cin>>n>>x>>pos;
        	int64_t numl=x-1,numr=n-x,sol=1,cnt=0;
        	int l=0,r=n;
        	while (l<r){
        		int mid=(l+r)/2;
        		if (mid<pos){
        			sol=(sol*numl)%mod;
        			numl--;
        			cnt++;
        			l=mid+1;
        		}
        		else if (mid>pos){
        			sol=(sol*numr)%mod;
        			numr--;
        			cnt++;
        			r=mid;
        		}
        		else l=mid+1;
        	}
        	for (int i=1;i<=n-cnt-1;i++) sol=(sol*i)%mod;
        	cout<<sol<<'\n';
        }
