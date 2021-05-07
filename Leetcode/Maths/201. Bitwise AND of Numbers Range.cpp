class Solution {
public:
    int ways(int left,int right){
       // cout<<left<<" "<<right<<endl;
        if(left==0) return 0;
        int l1 = log2(left);
        int r1 = log2(right);
       // cout<<left<<" "<<right<<" "<<l1<<" "<<r1<<endl;
        if(l1 == r1) return pow(2,l1) + ways(left-pow(2,l1),right-pow(2,r1));
        else return 0;
    }
    int rangeBitwiseAnd(int left, int right) {
        int i,j,k,n,m;
        if(left==right || left==0) return left;
        return ways(left,right);
    }
};
