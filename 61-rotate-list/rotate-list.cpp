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
    ListNode* rotate(ListNode* head){
        ListNode* current = head;
        int buffer = -1;
        while (current){
            swap(buffer, current->val);
            current = current->next;
        }

        swap(head->val, buffer);
        return head;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next) return head;
        ListNode* current = head;
        int count = 0;

        while (current){
            count++;
            current = current->next;
        }
        for (int i = 0; i < k%count; i++) head = rotate(head);
        return head;
    }
};