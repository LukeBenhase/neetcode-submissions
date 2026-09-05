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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* dummy = new ListNode();
        ListNode* currentNode = dummy;

        while (list1 != nullptr && list2 != nullptr){
            // check the value of each and add the smaller one. 
            if (list1->val > list2->val){
                // add list 2
                currentNode->next = list2;
                list2 = list2->next;
            }
            else {
                currentNode->next = list1;
                list1 = list1->next;
            }
            currentNode = currentNode->next;

        }
        // add whatever list is left
        if (list1 == nullptr ){
            currentNode->next = list2;
        }
        else{
            currentNode->next = list1;
        }
        return dummy->next;

    }
};
