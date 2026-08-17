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
    ListNode* revise(ListNode* head, int n) {

        ListNode* f = head;
        ListNode* s = head;

        for(int i = 0; i < n; i++) f = f->next;

        if(f == NULL) return head->next;

        while(f->next) {

            s = s->next;
            f = f->next;
        }

        s->next = s->next->next;

        return head;
    }

    ListNode* removeNthFromEnd(ListNode* head, int n) {
        return revise(head, n);

    // Method 1
        ListNode* fast = head;
        for(int i = 0; i < n; i++) fast = fast->next;

        // Edge Case when n is equal to size of LL
        if(fast == nullptr) {
            
            ListNode* newHead = head->next;
            delete head;
            return newHead;
        }

        // slow stop at (n - 1)th node from last 
        ListNode* slow = head;
        while(fast->next != nullptr) {

            slow = slow->next;
            fast = fast->next;
        }

        // delete the n-th node
        ListNode* delNode = slow->next;
        slow->next = slow->next->next;

        delete delNode;

        return head;


    // Method 2
        // int size = 0;

        // ListNode* temp = head;

        // while(temp) {

        //     temp = temp->next;
        //     size++;
        // }

        // // Edge Case (if N is equal to size of LL then return new Head)
        // if(size == n) {
            
        //     ListNode* newHead = head->next;
        //     delete head;

        //     return newHead;
        // }

        // int res = size - n;
        // res--;

        // temp = head;

        // while(res--) {

        //     temp = temp->next;
        // }

        // ListNode* delNode = temp->next;

        // temp->next = temp->next->next;

        // delete delNode;

        // return head;
    }
};