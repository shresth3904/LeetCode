/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> hash;

        Node* current = head;
        while (current){
            Node* buffer = new Node(current->val);
            hash[current] = buffer;
            current = current->next;
        }

        current = head;

        while (current){
            hash[current]->next = hash[current->next];
            hash[current]->random = hash[current->random];
            current = current -> next;
        }

        return hash[head];
    }
};