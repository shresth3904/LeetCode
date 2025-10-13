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

    ListNode* getmiddle(ListNode* head){
        if (!head || !head->next) return head;
        ListNode* slow = head;
        ListNode* fast = head->next;

        while (fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }

    ListNode* mergeSort(ListNode* head){
        if (!head || !head->next) return head;

        ListNode* mid = getmiddle(head);
        ListNode* right = mid->next;
        mid->next = nullptr;

        ListNode* leftSorted = mergeSort(head);
        ListNode* rightSorted = mergeSort(right);

        return merge(leftSorted, rightSorted);
    }

    ListNode* merge(ListNode* left, ListNode* right){
        if (!left) return right;
        if (!right) return left;

        if (left->val < right->val){
            left->next = merge(left->next, right);
            return left;
        }   else{
            right->next = merge(left, right->next);
            return right;
        }
    }

    ListNode* sortList(ListNode* head) {
        return mergeSort(head);
    }
};