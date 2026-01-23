struct node{
    int data;
    node* prev;
    node* next;
    node(int val){
        data = val;
        prev = nullptr;
        next = nullptr;
    }
};

class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        node* head = new node(nums[0]);
        node* curr = head;
        for (int i = 1; i < nums.size(); i++){
            node* temp = new node(nums[i]);
            curr->next = temp;
            temp->prev = curr;

            curr = curr->next;
        }
        int count = 0;
        while (head -> next != nullptr){
            int minSum = INT_MAX;
            node* target = nullptr;
            bool sorted = true;

            node* curr = head;
            while (curr->next){
                int sum = curr->data + curr->next->data;
                if (sum < minSum){
                    minSum = sum;
                    target = curr;
                }

                if (curr->data > curr->next->data) sorted = false;
                curr = curr->next;
            }

            if (sorted) break;

            if (target){target-> data = minSum;
            node* req = target->next->next;
            delete target->next;

            if (req) {
                req->prev = target;
            }
            target->next = req;
            }
            count++;
        }

        return count;
    }
};