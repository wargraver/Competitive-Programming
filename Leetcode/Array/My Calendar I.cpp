class MyCalendar {
public:
    vector<pair<int,int>> vect;
    MyCalendar() {
        this->vect.clear();
    }
    
    bool book(int start, int end) {
         int flag=0;
        for(int i=0;i<vect.size();i++){
            int low = vect[i].first,high = vect[i].second;
            if(end<=low || start>=high) continue;
            else flag=1;
        }
        if(flag==1) return false;
        else this->vect.push_back({start,end});
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */
