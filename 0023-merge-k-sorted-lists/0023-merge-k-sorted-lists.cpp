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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        multiset<int> st;

        for(auto it : lists) {
            while(it) {
                st.insert(it->val);
                it = it->next;
            }
        }

        ListNode* head = new ListNode(-1);
        ListNode* node = head;

        for(auto it : st) {
            ListNode* temp = new ListNode(it);
            node->next = temp;
            node = temp;
        }

        return head->next;
    }
};