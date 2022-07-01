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
    bool isPalindrome(ListNode* head) {
        ListNode *c = head, *r = head;
        if(c -> next == NULL) {
            return true;
        }
        if(c -> next -> next == NULL) {
            return head -> val == head -> next -> val;
        }
        c = head;
        while(r -> next != NULL) {
            c = c -> next;
            r = r -> next;
            if(r -> next != NULL) {
                r = r -> next;
            }
        }
        r = c;
        c = head;
        ListNode *after = r -> next;
        r -> next = NULL;
        while(after -> next != NULL) {
            ListNode *temp = after -> next;
            after -> next = r;
            r = after;
            after = temp;
        }
        after -> next = r;
        r = after;
        c = head;
        while(c != NULL and r != NULL) {
            if(r -> val != c -> val) {
                return false;
            }
            if(r->next == NULL and c -> next == NULL) {
                break;
            }
            r = r->next;
            c = c->next;
        }
        return true;
    }
};