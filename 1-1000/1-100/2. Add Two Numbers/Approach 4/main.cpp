class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = l1;
        ListNode* prev = nullptr;
        int carry = 0;

        while (l1 && l2) {
            int sum = l1->val + l2->val + carry;
            l1->val = sum % 10;
            carry = sum / 10;
            prev = l1;
            l1 = l1->next;
            l2 = l2->next;
        }

        if (l2) {
            prev->next = l2;
            l1 = l2;
        }

        while (l1 && carry) {
            int sum = l1->val + carry;
            l1->val = sum % 10;
            carry = sum / 10;
            prev = l1;
            l1 = l1->next;
        }

        if (carry) {
            prev->next = new ListNode(carry);
        }

        return head;
    }
};
