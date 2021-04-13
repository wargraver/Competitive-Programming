class Node{
    public:
    Node* a[26];
    bool isend;
    Node(){
        for(int i=0;i<26;i++) this->a[i]=NULL;
        this->isend=false;
    }
};
class Trie {
public:
    /** Initialize your data structure here. */
    Node *root;
    Trie() {
        this->root=new Node();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        int i=0,j=word[0]-'a';
        Node *curr = this->root;
        while(i<word.size() && curr->a[j]!=NULL){
            curr=curr->a[j];
            i++;j=j=word[i]-'a';
        }
        if(i==word.size()) curr->isend=true;
        else{
            while(i<word.size()){
                Node* temp=new Node();
                j=word[i]-'a';
                curr->a[j]=temp;
                curr=temp;
                i++;
            }
            curr->isend=true;
        }
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        int i,j,k,n;
        Node* curr=this->root;
        for(i=0;i<word.size();i++){
            j=word[i]-'a';
            if(curr->a[j]==NULL) return false;
            else curr=curr->a[j];
        }
        if(curr->isend==true) return true;
        else return false;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        int i=0,j=0,flag=0;
        Node *curr = root;
        while(i<prefix.size()){
              if(curr->a[prefix[i]-'a']==NULL) return false;
              curr=curr->a[prefix[i]-'a'];
              i++;
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
