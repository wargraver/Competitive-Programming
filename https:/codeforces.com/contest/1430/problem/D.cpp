#include<bits/stdc++.h>
using namespace std;
int T,n,s[200010],cnt,now,ans;
char a[200010];
int main(){
	scanf("%d",&T);
	while(T--){
		now=1,cnt=0,ans=0;
		scanf("%d",&n);
		scanf("%s",a+1);
		for(int i=1;i<=n;i++){
			if(a[i]==a[i-1])s[cnt]++;
			else s[++cnt]=1;
		}
		for(int i=1;i<=cnt;i++){
			while(now<=cnt&&s[now]==1)now++;
			if(now<=cnt)s[now]--;
			if(now>cnt)i++;
			if(i==now)now++;
			ans++;
		}
		printf("%d\n",ans);
	}
} 
