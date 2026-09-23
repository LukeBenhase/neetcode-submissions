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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int sum, carryover = 0;
        ListNode* result = new ListNode();
        ListNode* cur = result;
        while(l1 != nullptr || l2 != nullptr){
            if (l1 == nullptr ){
                sum = l2->val+carryover;
                l2 = l2->next;
            }
            else if (l2 == nullptr ){
                sum = l1->val + carryover;
                l1 = l1->next;
            }else { 
                sum = l1->val + l2->val+carryover;
                l1 = l1->next;
                l2 = l2->next;
            }
            carryover = sum / 10;
            cur->next = new ListNode(sum%10);
            cur = cur->next;
        }
        // add the carry on to the end
        if ( carryover != 0)
            cur->next = new ListNode(carryover);
        return result->next;
    }
};
