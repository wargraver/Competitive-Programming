class Solution {
public:
    int majorityElement(vector<int>& a) {
         int ct1=0;
        int c=a[0];
        for(int i=0;i<a.size();i++){
            if(c==a[i]) ct1++;
            else ct1--;
            if(ct1<=0){
                c=a[i];
                ct1=1;
            }
        }
        return c;
    }
};
