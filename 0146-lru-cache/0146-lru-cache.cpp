class LRUCache {
 
    struct Node{
        int key, value;
        Node *prev, *next;
        Node(int k, int v){
            this->key = k;
            this->value = v;
            prev = nullptr;
            next = nullptr;
        }
    };
    
    unordered_map<int, Node*> mpp;    
    int capacity;                     
     
    Node *head = new Node(-1,-1), *tail = new Node(-1,-1);
    
public:
    LRUCache(int capacity) {
        
        head->next = tail;
        tail->prev = head;
        this->capacity = capacity;
    }
    
    void deleteNode(Node* node){
        Node* prevNode = node->prev;
        Node* nextNode = node->next;
        prevNode->next = nextNode;
        nextNode->prev = prevNode;
    }
    void insertAfterHead(Node* node){
        Node* currAfterHead = head->next;
        head->next = node;
        node->next = currAfterHead;
        node->prev = head;
        currAfterHead->prev = node;
    }

    int get(int key) {
     if(mpp.find(key) == mpp.end()) return -1;
        
        Node* node = mpp[key];
        
       
        deleteNode(node);
        insertAfterHead(node);
        
        return node->value;
    }
    
    void put(int key, int val) {
       
        if(mpp.find(key) != mpp.end()){    //key already exists but new value  
            Node* node = mpp[key]; 
            node->value = val;
            deleteNode(node);
            insertAfterHead(node);
        }
        else{
           
            if(mpp.size() == capacity){
                Node* node = tail->prev;
                mpp.erase(node->key);
                deleteNode(node);
            }
            
          
            Node* node = new Node(key, val);
            mpp[key] = node;
            insertAfterHead(node);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */