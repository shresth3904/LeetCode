/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {

        if (!head || k == 1) return head;
        vector<ListNode*> grp;
        ListNode* current = head;
        int count = 0;
        ListNode* start = nullptr;
        while (current){
            grp.push_back(current);
            count++;
            
            if (count == k){
                ListNode* next = grp[k-1]->next;
                for (int i = count-1; i > 0; i--){
                    grp[i]->next = grp[i-1];
                }

                grp[0]->next = next;
                if (start) start->next = grp[count-1];
                else head = grp[count-1];
                start = grp[0];
                grp.clear();
                count = 0;
                current = grp[0];
            }

            current = current->next;
        }
        if (start && !grp.empty()) start->next = grp[0];
        return head;
    }
};