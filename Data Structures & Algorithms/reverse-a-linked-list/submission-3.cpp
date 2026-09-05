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
    ListNode* reverseList(ListNode* head) {
        ListNode* dummy = new ListNode();
        ListNode* head2 = dummy->next;
        ListNode* temp;
        while (head != nullptr){
            dummy->next = head;
            temp = head->next;
            head->next = head2;
            head2 = head;

            head = temp;

        }
        return dummy->next;

    }
};
