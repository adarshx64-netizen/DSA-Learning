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
    bool isPalindrome(ListNode* head) {
        
        if(!head || !head->next) return head;

        ListNode* slow = head;
        ListNode* fast = head;

        while(fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* reverse = reverseLL(slow->next);

        while(reverse) {

            if(head->val != reverse->val) return false;

            head = head->next;
            reverse = reverse->next;
        }

        return true;
    }

    ListNode* reverseLL(ListNode* node) {

        ListNode* temp = node;
        ListNode* prev = NULL;

        while(temp) {

            ListNode* front = temp->next;

            temp->next = prev;
            prev = temp;
            temp = front;
        }

        return prev;
    }
};