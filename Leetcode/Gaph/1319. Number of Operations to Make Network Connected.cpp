class Solution {
public:
    int find_parent(int arr[],int i){
        while(arr[i]!=i) i=arr[i];
        return i;
    }
    void join(int arr[],int x,int y){
        int m1 = find_parent(arr,x);
        int m2 = find_parent(arr,y);
        arr[m1] = m2;
    }
    int makeConnected(int n, vector<vector<int>>& c) {
        int i,j,k,n1,m;
        n1=c.size();
        int ct=0;
        int arr[n];
        for(i=0;i<n;i++) arr[i]=i;
        for(i=0;i<n1;i++){
            int j = c[i][0];
            int k = c[i][1];
            if(find_parent(arr,j)==find_parent(arr,k)) ct++;
            else{
                join(arr,j,k);
            }
        }
        cout<<ct<<endl;
        int kt=0;
        for(i=0;i<n;i++){
            if(arr[i]==i) kt++;
        }
        if(kt>ct+1) return -1;
        else return kt-1;
    }
};
