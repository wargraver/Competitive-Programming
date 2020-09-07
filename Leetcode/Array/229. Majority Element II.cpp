class Solution {
public:
    vector<int> majorityElement(vector<int>& a) {
        int cand1=-1e9,cand2=-1e9,ct1=0,ct2=0,n=a.size();
        for(int i=0;i<n;i++){
            if(cand1==a[i]) ct1++;
            else if(cand2==a[i]) ct2++;
            else if(ct1==0){
                cand1=a[i];
                ct1++;
            }
            else if(ct2==0){
            cand2=a[i];
                ct2++;
            }
            else {
              ct1--;
              ct2--;
            }
        }
        ct1=0;ct2=0;
        for(int i=0;i<n;i++){
          if(cand1==a[i]) ct1++;
          if(cand2==a[i]) ct2++;
        }
        vector<int> vect;
        if(ct1>n/3) vect.push_back(cand1);
        if(ct2>n/3 && cand1!=cand2) vect.push_back(cand2);
        return vect;
    }
};
