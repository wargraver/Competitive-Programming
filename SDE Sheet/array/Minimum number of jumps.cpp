class Solution{
  public:
    int minJumps(int a[], int n){
       int i=0,j=0,k,m,ct=0,flag=0;
       int max1=0,max2=0;
       j=min(a[0],n-1);max1=min(a[0],n-1);i=0;
       while(i!=n){
           if(j>i){
               max1=max(max1,min(n-1,i+a[i]));
               i++;
           }
           else if(j==i){
               ct++;
                max1=max(max1,min(n-1,i+a[i]));
               j=max1;
               if(i==j && i!=n-1) return -1;
               i++;
           }
       }
       return ct;
    }
};
