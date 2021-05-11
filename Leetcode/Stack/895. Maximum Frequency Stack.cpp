//https://leetcode.com/problems/maximum-frequency-stack/
class FreqStack {
public:
    int max_freq;
    map<int,int> freq;
    map<int,stack<int>> dict;
    FreqStack() {
        this->max_freq=0;
    }
    
    void push(int val) {
         this->freq[val]++;
        // cout<<val<<" "<<this->freq[val]<<endl;
         int kt = freq[val];
         this->dict[kt].push(val);
         this->max_freq = max(this->max_freq,this->freq[val]);
    }
    
    int pop() {
        auto it = this->dict.find(this->max_freq);
        int kt = it->second.top();
        cout<<kt<<" ";
        it->second.pop();
        if(it->second.empty()==true){
           this->dict.erase(it); 
        }
        if(dict.size()==0){
            this->max_freq=0;
            this->freq.clear();
        }
        else{
        auto mt = this->dict.end();
        mt--;
        this->freq[kt]--;
        this->max_freq = mt->first;
        //cout<<max_freq<<" "<<"freq"<<endl;
        //cout<<kt<<endl;
        }
        return kt;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */
