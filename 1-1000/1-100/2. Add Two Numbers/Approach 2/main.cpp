// Iterative digit-by-digit addition with a dummy head.
// Time: O(m + n), Space: O(1) auxiliary (the result list is O(m + n)).
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode dummy(0);
        ListNode* curr = &dummy;
        int carry = 0;

        while (l1 || l2 || carry) {
            int sum = carry;
            if (l1) {
                sum += l1->val;
                l1 = l1->next;
            }
            if (l2) {
                sum += l2->val;
                l2 = l2->next;
            }
            curr->next = new ListNode(sum % 10);
            carry = sum / 10;
            curr = curr->next;
        }

        return dummy.next;
    }
};
