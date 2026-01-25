class LRUCache {
    int cap;
    unordered_map<int, int> hash;
    vector<int> q;
public:
    LRUCache(int capacity) {
        cap = capacity;
    }
    
    int get(int key) {
        if (hash.find(key) != hash.end()){
            for (int i = 0; i < q.size(); i++){
                if (q[i] == key){
                    q.erase(q.begin() + i);
                    break;
                }
            }
            q.push_back(key);
            return hash[key];
        }

        return -1;
    }
    
    void put(int key, int value) {
        if (hash.find(key) != hash.end()){
            for (int i = 0; i < q.size(); i++){
                if (q[i] == key){
                    q.erase(q.begin() + i);
                    break;
                }
            }
        }
        else if (hash.size() >= cap){
            hash.erase(q[0]);
            q.erase(q.begin() + 0);
        }

        hash[key] = value;
        q.push_back(key);
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */