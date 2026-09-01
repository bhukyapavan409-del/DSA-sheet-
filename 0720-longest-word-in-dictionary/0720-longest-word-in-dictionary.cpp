
class TrieNode{
    public:
    TrieNode*children[26];
    bool isEnd;
    TrieNode(){
        isEnd=false;
        for(int i=0;i<26;i++){
            children[i]=nullptr;
        }
    }
};

class Solution {
public:

    void insert(TrieNode*root,string word){

        TrieNode*node=root;
        for(char ch:word){
            int index=ch-'a';
            if(node->children[index]==nullptr){
                node->children[index]=new TrieNode();
            }
            node=node->children[index];
        }
        node->isEnd=true;
    }

    bool check(TrieNode*root,string word){
        TrieNode*node=root;
        for(char ch:word){
            int index=ch-'a';
            node=node->children[index];
            if(!node->isEnd){
                return false;
            }
        }
        return true;
    }

    string longestWord(vector<string>& words) {
        TrieNode*root=new TrieNode();
        for(string word:words){
            insert(root,word);
        }
        string ans="";
        for(string word:words){
            if(check(root,word)){
                if(word.length()>ans.length()|| word.length()==ans.length()&& word<ans){
                    ans=word;
                }
            }
        }
        return ans;
    }
};