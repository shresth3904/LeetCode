#include <vector>
#include <queue>

using namespace std;

struct Node {
    long long value;
    int index;
    Node* prev;
    Node* next;
    bool valid;
    int version;

    Node(long long v, int idx) : value(v), index(idx), prev(nullptr), next(nullptr), valid(true), version(0) {}
};

struct Pair {
    long long sum;
    int index;
    Node* leftNode;
    Node* rightNode;
    int leftVersion;
    int rightVersion;

    bool operator>(const Pair& other) const {
        if (sum != other.sum) {
            return sum > other.sum;
        }
        return index > other.index;
    }
};

class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        int n = nums.size();
        if (n < 2) return 0;

        vector<Node*> nodes;
        nodes.reserve(n);
        
        Node* head = new Node(nums[0], 0);
        nodes.push_back(head);
        Node* curr = head;
        int inversionCount = 0;

        priority_queue<Pair, vector<Pair>, greater<Pair>> pq;

        for (int i = 1; i < n; i++) {
            Node* newNode = new Node(nums[i], i);
            nodes.push_back(newNode);
            
            curr->next = newNode;
            newNode->prev = curr;

            if (curr->value > newNode->value) {
                inversionCount++;
            }

            pq.push({curr->value + newNode->value, i - 1, curr, newNode, 0, 0});
            curr = newNode;
        }

        if (inversionCount == 0) return 0;

        int operations = 0;

        while (inversionCount > 0 && !pq.empty()) {
            Pair top = pq.top();
            pq.pop();

            Node* left = top.leftNode;
            Node* right = top.rightNode;

            if (!left->valid || !right->valid) continue;
            if (left->next != right) continue;
            if (left->version != top.leftVersion || right->version != top.rightVersion) continue;

            if (left->value > right->value) inversionCount--;
            if (left->prev && left->prev->value > left->value) inversionCount--;
            if (right->next && right->value > right->next->value) inversionCount--;

            long long newSum = left->value + right->value;
            
            left->value = newSum;
            left->version++;
            left->next = right->next;
            
            if (right->next) {
                right->next->prev = left;
            }
            
            right->valid = false;
            operations++;

            if (left->prev && left->prev->value > left->value) inversionCount++;
            if (left->next && left->value > left->next->value) inversionCount++;

            if (inversionCount == 0) break;

            if (left->prev) {
                pq.push({left->prev->value + left->value, 
                         left->prev->index, 
                         left->prev, 
                         left, 
                         left->prev->version, 
                         left->version
                });
            }
            if (left->next) {
                pq.push({left->value + left->next->value, 
                         left->index, 
                         left, 
                         left->next, 
                         left->version, 
                         left->next->version
                });
            }
        }

        return operations;
    }
};