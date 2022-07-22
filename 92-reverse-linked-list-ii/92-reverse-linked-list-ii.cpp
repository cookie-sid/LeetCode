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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(left == right) {
            return head;
        }
        
        ListNode* h = head, *prev = NULL;
        int curr = 1;
        while(curr != left) {
            curr++;
            prev = h;
            h = h -> next;
        }
        
        ListNode* firstNext = prev;
        ListNode* start = h, *newPrev = h, *newLast = h;
        start = start -> next;
        while(curr != right) {
            curr++;
            ListNode* temp = start -> next == NULL ? NULL : start -> next;
            start -> next = newPrev;
            if(curr == left + 1) {
                newPrev -> next = NULL;
            }
            newPrev = start;
            start = temp;
        }
        ListNode* g = left == 1 ? newPrev : head;
        if(firstNext != NULL)
            firstNext -> next = newPrev;
        
        newLast -> next = start;
        
        
        return g;
    }
};