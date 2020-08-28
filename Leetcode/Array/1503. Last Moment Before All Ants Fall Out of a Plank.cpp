class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        int n1=(int)left.size();
        int n2=(int)right.size();
        sort(left.begin(),left.end());
        sort(right.begin(),right.end());
        reverse(left.begin(),left.end());
        int c1=0,c2=n,i,j,k;
        if(n1>=1) c1=left[0];
        if(n2>=1) c2=right[0];
        return max(abs(n-c2),abs(0-c1));
        
    }
};
