class LRUCache {
public:
    struct Node{
        int val;
        int key;
        Node *next;
        Node *prev;
        Node(int val, int key) : val(val), key(key), next(nullptr), prev(nullptr) {}
    }*head = nullptr, *tail = nullptr;
    int cap = 0;
    unordered_map<int, Node*> map;

    LRUCache(int capacity) {
        cap = capacity;
    }
    
    int get(int key) {
        if (map.find(key) != map.end()) {
            Node* node = map[key];
            int value = node->val;
            deleteNode(node);
            put(key, value);
            return value;
        }
        return -1;
    }

    void deleteNode(Node* node) {
        if (node->prev) {
            node->prev->next = node->next;
        } else {
            head = node->next;
        }
        if (node->next) {
            node->next->prev = node->prev;
        } else {
            tail = node->prev;
        }
    }

    void put(int key, int value) {
        if (map.find(key) != map.end()) {
            deleteNode(map[key]);
            delete map[key];
        } else if (map.size() >= cap) {
            int tailKey = tail->key;
            deleteNode(tail);
            delete map[tailKey];
            map.erase(tailKey);
        }
        
        Node *newNode = new Node(value, key);
        newNode->next = head;
        if (head) {
            head->prev = newNode;
        }
        head = newNode;
        if (!tail) {
            tail = head;
        }
        map[key] = newNode;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */