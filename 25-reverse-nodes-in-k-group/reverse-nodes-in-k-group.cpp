class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {

        ListNode dummy(0);
        dummy.next = head;

        ListNode* prev = &dummy;

        while (true) {

            // Find the kth node
            ListNode* kth = prev;

            for (int i = 0; i < k; i++) {
                kth = kth->next;

                if (kth == nullptr)
                    return dummy.next;
            }

            // Save the node after the group
            ListNode* nextGroup = kth->next;

            // Reverse the group
            ListNode* prevNode = nextGroup;
            ListNode* curr = prev->next;

            while (curr != nextGroup) {
                ListNode* next = curr->next;
                curr->next = prevNode;
                prevNode = curr;
                curr = next;
            }

            // Connect previous part to reversed group
            ListNode* oldFirst = prev->next;
            prev->next = kth;

            // Move prev to the end of reversed group
            prev = oldFirst;
        }
    }
};