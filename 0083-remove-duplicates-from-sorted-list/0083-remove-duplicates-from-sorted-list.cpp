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
    ListNode* deleteDuplicates(ListNode* head) {

        if(!head) return head;

        ListNode* s = head;
        ListNode* f = head->next;

        while(f) {

            if(f->val == s->val) {
                
                ListNode* temp = f;
                f = f->next;
                delete temp;
            }

            else {

                s->next = f;
                s = f;
                f = f->next;
            }
        }

        s->next = NULL;
        
        return head;
    }
};