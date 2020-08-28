class Solution {
public:
    int maxArea(vector<int>& vect) {
        int i,j,k,n=(int)vect.size();
        int l=0,r=n-1;
        int area=0;
        while(l<r){
            area=max(area,min(vect[l],vect[r])*(r-l));
            if(vect[l]<vect[r]) l++;
            else r--;
        }  
        return area;
    }
};
