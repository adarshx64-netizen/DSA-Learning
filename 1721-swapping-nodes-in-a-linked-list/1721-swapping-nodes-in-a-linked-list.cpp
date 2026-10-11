class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        int n = 0;

        ListNode* node = head;
        while(node) {
            n++;
            node = node->next;
        }

        if(n == 1) return head;

        int cnt = 0;
        ListNode* n1 = head;
        ListNode* n2 = head;
        ListNode* curr = head;

        while(curr) {
            
            if(cnt == k-1) n1 = curr;
            if(cnt == n-k) n2 = curr;

            cnt++;
            curr = curr->next;
        }

        int x = n1->val;
        n1->val = n2->val;
        n2->val = x;

        return head;
    }
};