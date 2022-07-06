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
    
    ListNode* getInt(ListNode *head) {
        if(head == NULL) {
            return NULL;
        }
        ListNode *slow = head;
        ListNode *fast = head;
        while(fast -> next != NULL) {
            slow = slow -> next;
            fast = fast -> next;
            if(fast -> next != NULL) {
                fast = fast -> next;
            }
            else {
                return NULL;
            }
            if(slow == fast) {
                return slow;
            }
        }
        return NULL;
    }
    
    ListNode *detectCycle(ListNode *head) {
        ListNode *inter = getInt(head);
        if(inter == NULL) {
            return NULL;
        }
        ListNode *t = head;
        while(t != inter) {
            t = t->next;
            inter = inter -> next;
        }
        return t;
    }
};