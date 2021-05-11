class Solution {
public:
    int ways(int n){
        if(n==0) return 0;
        else if(n==1) return 1;
        else if(n==2 || n==3) return 2;
        else return 1+min(n%2+ways(n/2),n%3+ways(n/3));
    }
    int minDays(int n) {
        int ans=ways(n);
        return ans;
    }
};
