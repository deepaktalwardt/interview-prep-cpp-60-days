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

// Solution 1 (Iterate over and add you go along)
// O(N): Time
// O(N): Space
class Solution
{
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
    {
        ListNode* dummy = new ListNode();
        ListNode* head = dummy;
        int carry = 0;
        int sum = 0;
        int curr_val = 0;
        while (l1 || l2 || carry)
        {
            int a = 0;
            int b = 0;
            if (l1)
            {
                a = l1->val;
                l1 = l1->next;
            }
            if (l2)
            {
                b = l2->val;
                l2 = l2->next;
            }
            sum = a + b + carry;
            if (sum >= 10)
            {
                carry = 1;
            }
            else
            {
                carry = 0;
            }
            head->next = new ListNode(sum % 10);
            head = head->next;
        }

        if (carry)
        {
            head->next = new ListNode(1);
        }

        return dummy->next;
    }
};
