int diff; 
vector<int> vect;
int buildtree(int i,int st,int en,vector<int> nums){
        if(st==en) return vect[i] = nums[st];
        else if(st>en) return 0;
        else{
            int mid = (st+en)/2;
            vect[i] = buildtree(2*i+1,st,mid,nums) +  buildtree(2*i+2,mid+1,en,nums);
            return vect[i];
        }
    }
int get_sum(int i,int st,int en,int left,int right){
    if(st>en) return 0;
    else if(st>right || en<left) return 0;
    else{
        if(st>=left && en<=right) return vect[i];
        else{
            int mid = (st+en)/2;
            return get_sum(2*i+1,st,mid,left,right) + get_sum(2*i+2,mid+1,en,left,right);
        }
    }
}
void get_updated(int i,int st,int en,int index,int val){
    if(st>en) return;
    else if(st==en && st==index){
        diff = val-vect[i];
        vect[i] = val;
        return;
    }
    else{
        if(st>index || en<index) return;
        else{
            int mid = (st+en)/2;
            get_updated(2*i+1,st,mid,index,val);
            get_updated(2*i+2,mid+1,en,index,val);
            vect[i] = vect[i]+diff;
        }
    }
}
class NumArray {
public:
    int cap;
    NumArray(vector<int>& nums) {
        int m = nums.size();
        vect.clear();
        for(int i=0;i<=4*m;i++) vect.push_back(0);
        int st=0,en=m-1;
        this->cap=en;diff=0;
        buildtree(0,st,en,nums);
    }
    void update(int index, int val) {
         int st=0,en=this->cap;
        get_updated(0,st,en,index,val);
    }
    
    int sumRange(int left, int right) {
        int st=0,en=this->cap;
        return get_sum(0,st,en,left,right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */
