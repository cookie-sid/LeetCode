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
    ListNode* partition(ListNode* head, int x) {
        ListNode* smaller = new ListNode(0), *biggerOrEqual = new ListNode(0), *firstOfBigger = biggerOrEqual, *firstOfSmaller = smaller;
        if(head == NULL or head -> next == NULL) {
            return head;
        }
        ListNode* p = head;
        while(p != NULL) {
            if(p -> val < x) {
                smaller -> next = p;
                smaller = smaller -> next;
            }
            else {
                biggerOrEqual -> next = p;
                biggerOrEqual = biggerOrEqual -> next;
            }
            
            p = p -> next;
        }
        if(firstOfSmaller -> next == NULL) {
            return firstOfBigger -> next;
        }
        biggerOrEqual -> next = NULL;
        smaller -> next = firstOfBigger -> next;
        
        
        return firstOfSmaller -> next;
    }
};