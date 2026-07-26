struct Node{
    int key;
    int value;
    Node* next;
    Node* prev;

    Node(int key, int value){
        this->key = key;
        this->value = value;
        next = nullptr;
        prev = nullptr;
    }
};

class LRUCache {
public:

    int cap;
    unordered_map<int, Node*> mp;
    Node* head;
    Node* tail;

    LRUCache(int capacity) {
        cap = capacity;

        head = new Node(-1,-1);
        tail = new Node(-1,-1);
        head->next = tail;
        tail->prev = head;
    }

    void addNode(Node* node){
        Node* temp = head->next;
        head->next = node;
        node->next = temp;
        temp->prev = node;
        node->prev = head;
    }

    void deleteNode(Node* node){
        Node* preNode = node->prev;
        Node* nxtNode = node->next;

        preNode->next = nxtNode;
        nxtNode->prev = preNode;
    }
    
    int get(int key) {
        if(mp.find(key) != mp.end()){
            Node* getNode = mp[key];
            int result = getNode->value;
            mp.erase(key);
            deleteNode(getNode);
            addNode(getNode);
            mp[key] = head->next;

            return result;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(mp.find(key) != mp.end()){
            Node* existing = mp[key];
            mp.erase(key);
            deleteNode(existing);
        }

        if(mp.size() == cap){
            Node* lru = tail->prev;
            mp.erase(lru->key);
            deleteNode(lru);
        }

        Node* newNode = new Node(key, value);
        addNode(newNode);
        mp[key] = head->next;
    }
};
