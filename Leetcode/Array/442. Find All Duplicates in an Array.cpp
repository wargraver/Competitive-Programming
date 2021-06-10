class Solution {
public:
    vector<int> findDuplicates(vector<int>& a) {
        int i,j,k,n,m,ct=0;
        vector<int> ans;
        set<int> dict;
        for(i=0;i<a.size();i++){
            if(i+1!=a[i]){
                k = a[i];
                a[i]=-1;int flag=0;
                if(a[i]!=i+1 && k==a[k-1]) {dict.insert(k);flag=1;a[i]=k;}
                while(k!=a[k-1]){
                    j = a[k-1];
                    a[k-1] = k;
                    if(a[j-1]==j){
                        a[i]=j;
                        flag=1;
                        dict.insert(j);
                        break;
                    }
                    k=j;
                    if(a[j-1]<=0) break;
                }
                if(flag==0) a[i]=i+1;
            }
            //for(k=0;k<a.size();k++) cout<<a[k]<<" ";
           // cout<<endl;
        }
        for(auto it=dict.begin();it!=dict.end();it++) ans.push_back(*it);
        return ans;
    }
};
