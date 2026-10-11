class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {

        ListNode* slow = head;
        ListNode* fast = head;

        while(--k) fast = fast->next;

        ListNode* n1 = fast;

        while(fast->next) {
            slow = slow->next;
            fast = fast->next;
        }

        ListNode* n2 = slow;
        swap(n1->val, n2->val);        

        return head;
    }
};