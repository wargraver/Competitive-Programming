class MedianFinder {
public:
    /** initialize your data structure here. */
    priority_queue<int,vector<int>,greater<int>> min1;
    priority_queue<int,vector<int>> max1;
    void addNum(int num) {
       int size1=max1.size(),size2=min1.size();
       if(size1==0) max1.push(num);
        else{
            if(num<max1.top()){
                max1.push(num);
                size1++;
                if(size1-size2==2){
                    int k=max1.top();
                    max1.pop();
                    min1.push(k);
                }
            }
            else{
                min1.push(num);
                size2++;
                if(size2-size1==1){
                    int k=min1.top();
                    min1.pop();
                    max1.push(k);
                }
            }
        }
    }
    
    double findMedian() {
        int size1=max1.size(),size2=min1.size();
        if((size1+size2)%2==0){
            int n1=max1.top(),n2=min1.top();
            int m=n1+n2;
            return (double)m/2;
        }
        else return max1.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
