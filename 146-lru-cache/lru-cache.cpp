struct node{
    int val;
    int key;
    node* prev;
    node* next;

    node(int a, int b){
        val = a;
        key = b;
    }
};

class LRUCache {
public:

    node* head = nullptr; 
    node* tail = nullptr;
    unordered_map<int, node*> hash;
    int cap;

    LRUCache(int capacity) {
        cap = capacity;
    }
    
    int get(int key) {
        if (hash.find(key) != hash.end()){
            if (hash[key] == tail){
                return hash[key]->val;
            }
            else if (hash[key] == head){
                head = head->next;
                head->prev = nullptr;
            }
            else {
                hash[key]->prev->next = hash[key]->next;
                hash[key]->next->prev = hash[key]->prev;
            }

            tail->next = hash[key];
            hash[key]->next = nullptr;
            hash[key]->prev = tail;
            tail = tail->next;
            return hash[key]->val;
        }

        return -1;
    }
    
    void put(int key, int value) {
        if (hash.find(key) != hash.end()){
            hash[key]->val = value;
            if (hash[key] == tail){
                return;
            }
            else if (hash[key] == head){
                head = head->next;
                head->prev = nullptr;
            }
            else {
                hash[key]->prev->next = hash[key]->next;
                hash[key]->next->prev = hash[key]->prev;
            }

            tail->next = hash[key];
            hash[key]->next = nullptr;
            hash[key]->prev = tail;
            tail = tail->next;
            return;
        }

        if (hash.size() >= cap) {
            node* temp = head;
            hash.erase(temp->key);
            if (head == tail){ 
                tail = nullptr;
                head = nullptr;
            }
            else {
                head = head->next;
                head->prev = nullptr;
            }
            delete temp;
        }

        node* temp = new node(value, key);
        if (!head){
            head = temp;
            tail = temp;
        }

        else {
            tail->next = temp;
            temp->prev = tail;
            tail = tail->next;
        }

        hash[key] = temp;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */