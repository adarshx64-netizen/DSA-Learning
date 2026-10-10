class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(!list1 && !list2) return NULL;
        if(!list1) return list2;
        if(!list2) return list1;
        return optimal(list1, list2);
    }

    ListNode* optimal(ListNode* list1, ListNode* list2) {
        ListNode* head = new ListNode(-1);
        ListNode* node = head;

        while(list1 && list2) {
            if(list1->val < list2->val) {
                node->next = list1;
                list1 = list1->next;
            }

            else {
                node->next = list2;
                list2 = list2->next;
            }

            node = node->next;
        }

        while(list1) {
            node->next = list1;
            node = node->next;
            list1 = list1->next;
        }

        while(list2) {
            node->next = list2;
            node = node->next;
            list2 = list2->next;
        }

        return head->next;
    }
};