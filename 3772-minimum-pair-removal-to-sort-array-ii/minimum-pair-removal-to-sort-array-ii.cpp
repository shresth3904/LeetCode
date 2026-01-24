struct node{
    long long val;
    int index;
    node* prev;
    node* next;
    bool valid = true;
    node(int data, int i){
        index = i;
        val = data;
        prev = nullptr;
        next = nullptr;
    }
};

typedef pair<long long, node*> Pair;

struct compare{
    bool operator()(const Pair& a, const Pair& b){
        if (a.first != b.first){
            return a.first > b.first;
        }
        return a.second->index > b.second->index;
    }
};

class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        priority_queue<Pair, vector<Pair>, compare> min_heap;
        node* head = new node(nums[0], 0);
        node* curr = head;
        int bad_pair = 0;

        for (int i = 1; i < nums.size(); i++){
            node* temp = new node(nums[i], i);
            temp->prev = curr;
            curr->next = temp;
            long long sum = (long long) curr->val + temp->val;
            min_heap.push({sum, curr});
            if (curr->val > temp->val) bad_pair++;
            curr = curr->next;
        }
        int count = 0;
        while (bad_pair > 0){
            auto top_ele = min_heap.top();
            min_heap.pop();
            
            //checking dead pairs
            if (!top_ele.second->valid ||!top_ele.second->next || !top_ele.second->next->valid || 
                (top_ele.first != (long long)top_ele.second->val + top_ele.second->next->val)) 
                continue;

            // bad_pairs calc
            node* first = top_ele.second;
            node* second = first->next;

            if (first->prev && first->prev->val > first->val) bad_pair--;
            if (first->val > second->val) bad_pair--;
            if (second->next && second->val > second->next->val) bad_pair--;

            //merging and recalulating bad pairs
            first->val = top_ele.first;
            first->next = second->next;
            if (second->next) second->next->prev = first;
            second-> valid = false;

            //recalculation

            if (first->prev && first->prev->val > first->val) bad_pair++;
            if (first->next && first->val > first->next->val) bad_pair++;

            //adding pairs in min_heap

            if (first->prev) min_heap.push({(long long)first->prev->val + first->val, first->prev});
            if (first->next) min_heap.push({(long long)first->val + first->next->val, first});
            
            count++;
        }

        return count;
    }
};