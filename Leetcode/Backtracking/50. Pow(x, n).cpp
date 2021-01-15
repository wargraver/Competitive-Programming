double ways(double x,int n){
    if(n==1) return x;
    else if(n==-1) return 1/x;
    else if(n%2==0) return ways(x,n/2)*ways(x,n/2);
    else if(n>=0) return ways(x,n/2)*x*ways(x,n/2);
    else return ways(x,n/2)*ways(x,n/2)*1/x;
}
class Solution {
public:
    double myPow(double x, int n) {
        if(n==0) return 1;
        return ways(x,n);
    }
};
