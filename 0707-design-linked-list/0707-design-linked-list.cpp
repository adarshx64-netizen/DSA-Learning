class MyLinkedList {
public:
    struct ListNode {
        int val;
        ListNode* next;

        ListNode(int x) {
            val = x;
            next = nullptr;
        }
    };

    ListNode* head;
    int size;

    MyLinkedList() {
        head = nullptr;
        size = 0;
    }

    int get(int index) {
        if(index < 0 || index >= size) return -1;

        ListNode* temp = head;

        while(index--) {
            temp = temp->next;
        }

        return temp->val;
    }

    void addAtHead(int val) {
        ListNode* newHead = new ListNode(val);
        newHead->next = head;
        head = newHead;

        size++;
    }

    void addAtTail(int val) {
        ListNode* tail = new ListNode(val);

        if(head == nullptr) {
            head = tail;
        } else {
            ListNode* temp = head;

            while(temp->next) {
                temp = temp->next;
            }

            temp->next = tail;
        }

        size++;
    }

    void addAtIndex(int index, int val) {
        if(index < 0 || index > size) return;

        if(index == 0) {
            addAtHead(val);
            return;
        }

        ListNode* curr = head;

        for(int i = 0; i < index - 1; i++) {
            curr = curr->next;
        }

        ListNode* node = new ListNode(val);
        node->next = curr->next;
        curr->next = node;

        size++;
    }

    void deleteAtIndex(int index) {
        if(index < 0 || index >= size) return;

        if(index == 0) {
            ListNode* temp = head;
            head = head->next;

            delete temp;
            size--;
            return;
        }

        ListNode* curr = head;

        for(int i = 0; i < index - 1; i++) {
            curr = curr->next;
        }

        ListNode* temp = curr->next;
        curr->next = temp->next;

        delete temp;
        size--;
    }
};