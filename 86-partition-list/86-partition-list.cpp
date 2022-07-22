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
        ListNode* smaller = NULL, *biggerOrEqual = NULL, *firstOfBigger = NULL, *firstOfSmaller = NULL;
        if(head == NULL or head -> next == NULL) {
            return head;
        }
        ListNode* p = head;
        while(p != NULL) {
            if(p -> val < x) {
                if(smaller == NULL) {
                    smaller = new ListNode(p -> val);
                    firstOfSmaller = smaller;
                }
                else {
                    smaller -> next = new ListNode(p -> val);
                    smaller = smaller -> next;
                }
            }
            else {
                if(biggerOrEqual == NULL) {
                    biggerOrEqual = new ListNode(p -> val);
                    firstOfBigger = biggerOrEqual;
                }
                else {
                    biggerOrEqual -> next = new ListNode(p -> val);
                    biggerOrEqual = biggerOrEqual -> next;
                }
            }
            
            p = p -> next;
        }
        
        if(smaller == NULL) {
            return firstOfBigger;
        }
        
        smaller -> next = firstOfBigger;
        
        
        return firstOfSmaller;
    }
};