    //https://codeforces.com/contest/677/problem/B
    #include<bits/stdc++.h>
    using namespace std;
    typedef long long ll;
    ll max1 =(ll)1e9;
    int main(){
     /* #ifndef ONLINE_JUDGE
      freopen("input.txt","r",stdin);
      freopen("output.txt","w",stdout);
      #endif*/
      string str;
      cin>>str;
      string code="CODEFORCES";
      ll i,j,k,n,m,ct=0,t,ans=0,flag=0;
      j=0;
      if(str.size()>=code.size()){
      for(i=0;i<code.size();i++){
      	j=0;k=0;
      	string str1=code.substr(0,i+1),str2=code.substr(i+1,code.size()-i);
      //	cout<<str1<<" "<<str2;
      	//cout<<endl;
        j=str.find(str1);
        k=str.find(str2);
        if((str1.size()==code.size())&&(j==0 || j==str.size()-code.size())){
        	flag=1;break;
    	}
    	else if(j==0){
    		ll l=str2.size()-1,o=str.size()-1;
    		while(l>=0){
    			if(str2[l]==str[o]){
    				l--;o--;
    			}
    			else break;
    		}
    		if(l==-1){
    			flag=1;break;
    		}
    	}
      }}
      if(flag==1) cout<<"YES";
      else cout<<"NO";
      return 0;
    }
