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
        ListNode *curr = head, *prev = head, *trav = head;
        int size = 1;
        while(trav -> next != NULL) {
            trav = trav -> next;
            size += 1;
        }
        n = size - n + 1;
        if(head -> next == NULL) {
            return NULL;
        }
        if(n == 1) {
            return curr -> next;
        }
        curr = curr -> next;
        int v = 2;
        while(v < n) {
            curr = curr -> next;
            prev = prev -> next;
            v++;
        }
        if(curr -> next == NULL) {
            prev -> next = NULL;
        }
        else {
            prev -> next = curr -> next;
        }
        return head;
    }
};