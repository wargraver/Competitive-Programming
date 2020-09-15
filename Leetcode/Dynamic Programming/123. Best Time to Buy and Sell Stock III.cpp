class Solution {
   /*   
        pos->current position
        t->transactions done
        bought->If current stock is bought
    */
    vector<vector<vector<int>>> mem;
    int recursion(vector<int>& prices,int pos,int t,bool bought)
    {
        if(pos>=prices.size() || t==0)      //Out of bounds case
            return 0;
        if(mem[bought][t][pos]!=-1)     //Return if already calculated
            return mem[bought][t][pos];
        
        //3 choices for a position-->Buy/Sell/Skip
        int result = recursion(prices,pos+1,t,bought);    //SKIP
        if(bought)
            result = max(result,recursion(prices,pos+1,t-1,false)+prices[pos]);   //SELL
        else
            result = max(result,recursion(prices,pos+1,t,true)-prices[pos]);    //BUY
        
        mem[bought][t][pos] = result;
        return result;
    }
public:
    int maxProfit(vector<int>& prices) {
        mem.resize(2,vector<vector<int>>(3,vector<int>(prices.size(),-1)));
        int res = recursion(prices,0,2,false);
        return res;
    }
};
