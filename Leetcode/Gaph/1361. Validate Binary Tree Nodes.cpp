class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& left, vector<int>& right) {
        queue<int> q;
        int indeg[n],i,j,k,ct=0;
        memset(indeg,0,sizeof(indeg));
        //memset(outdeg,0,sizeof(outdeg));
        for(i=0;i<n;i++){
            if(left[i]!=-1){
                indeg[left[i]]++;
                if(indeg[left[i]]>=2) return false;
            }
            if(right[i]!=-1){
                indeg[right[i]]++;
                if(indeg[right[i]]>=2) return false;
            }
        }
        for(i=0;i<n;i++){
            if(indeg[i]==0) {
                q.push(i);
            }
        }
        if(q.size()>1 or q.size()==0) return false;
        while(q.empty()==false){
            k = q.front();
            q.pop();
            ct++;
           if(left[k]!=-1) {
               indeg[left[k]]--;
               if(indeg[left[k]]==0) q.push(left[k]);
           }
           if(right[k]!=-1) {
               indeg[right[k]]--;
               if(indeg[right[k]]==0) q.push(right[k]);
           }
            
        }
        if(ct==n) return true;
        else return false;
    }
};
