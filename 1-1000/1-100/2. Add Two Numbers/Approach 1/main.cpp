class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        vector<int> a, b;
        while (l1) { a.push_back(l1->val); l1 = l1->next; }
        while (l2) { b.push_back(l2->val); l2 = l2->next; }

        vector<int> res;
        int carry = 0, i = 0;
        while (i < a.size() || i < b.size() || carry) {
            int sum = carry;
            if (i < a.size()) sum += a[i];
            if (i < b.size()) sum += b[i];
            res.push_back(sum % 10);
            carry = sum / 10;
            i++;
        }

        ListNode dummy(0);
        ListNode* curr = &dummy;
        for (int d : res) {
            curr->next = new ListNode(d);
            curr = curr->next;
        }
        return dummy.next;
    }
};
