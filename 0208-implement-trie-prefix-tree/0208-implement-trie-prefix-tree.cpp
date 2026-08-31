struct Node{
    Node*links[26]={nullptr};
    bool flag=false;
    bool containskey(char ch){
        return links[ch-'a']!=nullptr;
    }
    void put(char ch,Node*node){
        links[ch-'a']=node;
    }
    Node*get(char ch){
        return links[ch-'a'];
    }
    void setEnd(){
        flag=true;
    }
    bool isEnd(){
        return flag;
    }
};


class Trie {
    private:
      Node*root;
public:
    Trie() {
        root=new Node();
        
    }
    
    void insert(string word) {
        Node*node=root;
        for(char ch:word){
            if(!node->containskey(ch)){
                node->put(ch,new Node());
            }
            node=node->get(ch);   // move to the next node
        }
        node->setEnd();   //mark flag as true in end 
        
    }
    
    bool search(string word) {
        Node*node=root;
        for(char ch: word){
            if(!node->containskey(ch)){
                return false;
            }
            node=node->get(ch);
        }
        return node->isEnd();
    }
    
    bool startsWith(string prefix) {
        Node*node=root;
        for(char ch:prefix){
            if(!node->containskey(ch)){
                return false;
            }
            node=node->get(ch);
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