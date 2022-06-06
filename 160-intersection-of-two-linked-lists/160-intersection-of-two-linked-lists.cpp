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
    
    ListNode* helper(ListNode* a, ListNode* b, int skipA, int skipB) {
        while(skipA > 0) {
            skipA--;
            a = a -> next;
        }
        while(skipB > 0) {
            b = b -> next;
            skipB--;
        }
        while(a -> next != NULL and b -> next != NULL and a != b) {
            a = a -> next;
            b = b -> next;
        }
        if(a == b) {
            return a;
        }
        return NULL;
    }
    
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int numOfNodesInA = 1, numOfNodesInB = 1;
        ListNode* hA = headA;
        ListNode* hB = headB;
        if(headA == NULL or headB == NULL)
            return NULL;
        while(hA -> next != NULL) {
            numOfNodesInA++;
            hA = hA -> next;
        }
        while(hB -> next != NULL) {
            numOfNodesInB++;
            hB = hB -> next;
        }
        hA = headA;
        hB = headB;
        if(numOfNodesInA < numOfNodesInB) {
            return helper(hA, hB, 0, numOfNodesInB - numOfNodesInA);
        }
        else if(numOfNodesInA > numOfNodesInB) {
            return helper(hA, hB, numOfNodesInA - numOfNodesInB, 0);
        }
        return helper(hA, hB, 0, 0);
    }
};