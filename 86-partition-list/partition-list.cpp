class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode a(0), b(0);
        ListNode *p = &a, *q = &b;

        while (head) {
            if (head->val < x) {
                p->next = head;
                p = p->next;
            } else {
                q->next = head;
                q = q->next;
            }
            head = head->next;
        }
        q->next = nullptr;
        p->next = b.next;
        return a.next;
    }
};