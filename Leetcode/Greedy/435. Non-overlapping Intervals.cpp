 bool arr(pair<int,int> A,pair<int,int> B){
        if(A.first!=B.first) return A.first<B.first;
        else return A.second<B.second;
    }
class Solution {
public:
   
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int i,j,k,n,m,ct=0;
        n=intervals.size();
        vector<pair<int,int>> vect;
        for(i=0;i<intervals.size();i++) vect.push_back({intervals[i][0],intervals[i][1]});
        sort(vect.begin(),vect.end(),arr);
       // for(i=0;i<vect.size();i++) cout<<vect[i].first<<" "<<vect[i].second<<endl;
        int st=-1e9,en=-1e9;
        for(i=0;i<n;i++){
            int st1= vect[i].first,en1 = vect[i].second;
            if(en<=st1 && st<=en1){
                ct++;
                st=st1;
                en=en1;
            }
            else{
                if(en1<=en){
                    st=st1;en=en1;
                }
                else continue;
            }
        }
        return vect.size()-ct;
    }
};
