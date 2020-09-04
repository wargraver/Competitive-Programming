class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& b) {
       vector<vector<int>> vect;
        vector<int> temp;
        multiset<pair<int,int>> dict;
        for(int i=0;i<b.size();i++) dict.insert({b[i][0],b[i][1]});
       vector<vector<int>> a;
        for(auto it=dict.begin();it!=dict.end();it++){
            temp.clear();
            int k=it->first,j=it->second;
            cout<<k<<" "<<j<<endl;
          temp.push_back(k);temp.push_back(j);
            a.push_back(temp);
        }temp.clear();
        if(a.size()==0) return vect;
        temp.push_back(a[0][0]);temp.push_back(a[0][1]);
        vect.push_back(temp);
        int i,j,k,n=a.size();
        for(i=1;i<n;i++){
            temp.clear();
             temp.push_back(a[i][0]);temp.push_back(a[i][1]);
            int l_st=vect[vect.size()-1][0],l_en=vect[vect.size()-1][1];
            if(l_en>=a[i][0] && l_en<=a[i][1]){
                vect[vect.size()-1][0]=min(a[i][0],l_st);
                vect[vect.size()-1][1]=max(a[i][1],l_en);
            }
            else if(a[i][0]>=l_st && a[i][1]<=l_en){
                vect[vect.size()-1][0]=min(a[i][0],l_st);
                vect[vect.size()-1][1]=max(a[i][1],l_en);
            }
            else vect.push_back(temp);
        }
        return vect;
    }
};
