class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        ListNode* dummyNode = new ListNode(-1);
        ListNode* curr = dummyNode;

        int carry = 0;
        while(l1 || l2) {

            int sum = carry;

            if(l1) sum += l1->val;
            if(l2) sum += l2->val;

            ListNode* temp = new ListNode(sum % 10);

            curr->next = temp;
            curr = temp;

            carry = sum / 10;

            if(l1) l1 = l1->next;
            if(l2) l2 = l2->next;
        }

        if(carry) {

            ListNode* temp = new ListNode(carry);
            curr->next = temp;
            curr = temp;
        }

        return dummyNode->next;
    }
};