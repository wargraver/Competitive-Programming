class Solution {
public:
    int search(vector<int>& a, int target) {
        int n=a.size()-1;
        int left=0,right=n;
        while(left<right){
            int mid=(left+right)/2;
            if(a[mid]>a[right]){
                left=mid+1;
            }
            else right=mid;
        }
        cout<<right;
        int i=right,j=n;
        while(i<=j){
            int mid=(i+j)/2;
            if(a[mid]>target) j=mid-1;
            else if(a[mid]<target) i=mid+1;
            else {return mid;}
        }
        i=0,j=right-1;
        if(right-1>=0){
        while(i<=j){
            int mid=(i+j)/2;
            if(a[mid]>target) j=mid-1;
            else if(a[mid]<target) i=mid+1;
            else return mid;
        }
        }
        return -1;
    }
};
