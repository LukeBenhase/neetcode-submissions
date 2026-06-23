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
        // i need 2 pointers to nodes
        ListNode* lastPtr = nullptr;
        ListNode* nextPtr;
        ListNode* thisPtr = head;
        
        //edge case of nothing 
        if (thisPtr == nullptr)
            return nullptr;

        
        while (thisPtr->next != nullptr){
            cout << thisPtr->val << endl;
            nextPtr = thisPtr->next;
            thisPtr->next = lastPtr;
            lastPtr = thisPtr;
            thisPtr = nextPtr;
        }
        thisPtr->next = lastPtr;
        return thisPtr;
    }
};
