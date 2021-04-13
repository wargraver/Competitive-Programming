int kthSmallest(int arr[], int l, int r, int k) {
        //code here
        int i,j,n;
        n=r+1;
        priority_queue<int> pq(arr,arr+n);
        
        for(i=1;i<=n-k;i++) pq.pop();
        return pq.top();
    }
