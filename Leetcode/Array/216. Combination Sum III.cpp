#include<bits/stdc++.h>
int a[]={1,2,3,4,5,6,7,8,9};
vector<vector<int>> vect;int kt=0;
void ways(int n,vector<int> str){
    if(n<0){
        vector<int> temp;
        for(int i=0;i<str.size();i++) temp.push_back(str[i]);
        vect.push_back(temp);
        kt++;
        return;
    }
    ways(n-1,str);
    str.push_back(a[n]);
    ways(n-1,str);
}
class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
       vector<int> str;
        ways(8,str);int ct=0;
        vector<vector<int>> ans;
        for(int i=0;i<512;i++){
        if(vect[i].size()==k){
            int sum=0;
            for(auto x:vect[i]) sum+=x;
            if(sum==n){
                ans.push_back(vect[i]);
                ct++;
            }
        }
        }
        return ans;
    }
};
