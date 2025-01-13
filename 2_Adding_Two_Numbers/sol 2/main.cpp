#include <new>

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        ListNode * sum_list = new ListNode();
        ListNode * temp = sum_list;
        int carry = 0;

        if(!l1 || !l2)
            return nullptr;

        while(l1 || l2 || carry) {

            int sum = carry;

            if(l1) {

                sum += l1->val;
                l1 = l1->next;

            }

            if(l2) {

                sum += l2->val;
                l2 = l2->next;

            }

            carry = sum / 10;
            temp->next = new ListNode(sum % 10);
            temp = temp->next;

        }

        return sum_list->next;
        
    }

};