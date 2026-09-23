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
    void reorderList(ListNode* head) {
        // this is just reverse linked list. but just half then merge the 2 lists
        ListNode* start = head;
        ListNode* reverse; 
        ListNode* fast = head;
        ListNode* slow = head;
        
        // find half way
        while(fast->next != nullptr){
            fast = fast->next;
            slow = slow->next;
            if (fast->next != nullptr)
                fast = fast->next;
        }

        // reverse the remaining list
        ListNode* prev = nullptr;
        ListNode* curr = slow->next;
        slow->next = nullptr; // Break the list into two halves here
        
        while(curr != nullptr){
            ListNode* nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }
        // merge the two lists
        //reverse = reverse->next;
        reverse = prev; // 'prev' is the head of the reversed second half
        while( start != nullptr && reverse != nullptr){
            // pull the nodes out and change pointers
            ListNode* f = start;
            ListNode* b = reverse;
            start = start->next;
            reverse = reverse->next;
            f->next = b;
            b->next = start;
        }
        


    }
};
