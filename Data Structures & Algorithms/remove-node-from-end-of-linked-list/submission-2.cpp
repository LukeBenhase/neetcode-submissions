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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // use two pointers to itterate down the list with the front pointer
        // being n places ahead and once *next = nullptr remove node at other pos        
        ListNode* fast = head;
        ListNode* slow = head;

        // loop for first pointer
        for(int i = 0; i < n; i++){ 
            fast = fast->next;
        }

        if (fast == nullptr)  
            return head = head->next;

        while ( fast->next != nullptr){
            // move both one place
            fast = fast->next;
            slow = slow->next;
        }
        
        slow->next = slow->next->next;
        return head;
    }
};
