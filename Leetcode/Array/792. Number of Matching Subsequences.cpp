class Solution {
public:
    int numMatchingSubseq(string S, vector<string>& vect) {
        int i,j,k,n,m,ct=0,t;
        vector<int> adj[26];
        for(i=0;i<S.size();i++){
          int diff=S[i]-'a';
          adj[diff].push_back(i+1);
        }
        for(i=0;i<vect.size();i++){
            cout<<vect[i]<<" ";
            int min_ind=1;int ans=-1;int flag=0;
            for(j=0;j<vect[i].size();j++){
                int diff=vect[i][j]-'a';ans=-1;
                cout<<vect[i][j]<<endl;
                int left=min_ind,right=adj[diff].size();
                while(left<=right){
                    int mid=(adj[diff][left]+adj[diff][right])/2;
                    if(adj[diff][mid-1]>min_ind){
                        right=mid-1;
                        ans=mid;
                   }
                    else left=mid+1;
                }
                if(ans==-1) {flag=0;break;}
                else {flag=1;min_ind=ans;}
            }
            if(flag==1) ct++;
      }
        cout<<ct<<endl;
        return ct;
    }
};
