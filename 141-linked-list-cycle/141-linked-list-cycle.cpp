/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head == NULL)
            return false;
        ListNode* jumpTwo = head;
        ListNode* jumpOne = head;
        
        while(jumpTwo -> next != NULL and jumpTwo -> next -> next != NULL) {
            jumpOne = jumpOne -> next;
            jumpTwo = jumpTwo -> next;
            jumpTwo = jumpTwo -> next;
            if(jumpOne == jumpTwo) 
                return true;
        }
        if(jumpTwo -> next == NULL or jumpTwo -> next -> next == NULL)
            return false;
        return true;
    }
};