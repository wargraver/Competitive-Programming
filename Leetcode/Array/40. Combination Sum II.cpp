set<vector<int>> vect3;
void ways(vector<int> a,vector<int> emp,int n,int sum){
    if(sum==0) {sort(emp.begin(),emp.end());
               // for(int i=0;i<emp.size();i++) cout<<emp[i]<<" ";
                //cout<<endl;
        vect3.insert(emp);return;}
    if(n<0) {emp.clear();return;}
    ways(a,emp,n-1,sum);
    emp.push_back(a[n]);
    if(sum>=a[n]) ways(a,emp,n-1,sum-a[n]);
}
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& a, int sum) {
        int i,j,k,n=a.size(),m;
        vector<int> emp;
        vect3.clear();
        ways(a,emp,n-1,sum);
       vector<vector<int>> vect;
        for(auto it=vect3.begin();it!=vect3.end();it++){
            vect.push_back(*it);
        }
        return vect;
    }
};
