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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL) {
            return head;
        }
        int n = 1;
        vector<int> vals;
        vals.push_back(head -> val);
        ListNode* temp = head;
        while(temp -> next != NULL) {
            n++;
            temp = temp -> next;
            vals.push_back(temp -> val);
        }
        k = k % n;
        temp = head;
        int ctr = n - k;
        while(temp -> next != NULL) {
            ctr >= n ? ctr = 0 : ctr = ctr;
            temp -> val = vals[ctr];
            ctr++;
            temp = temp -> next;
        }
        ctr >= n ? ctr = 0 : ctr = ctr;
        temp -> val = vals[ctr];
        return head;
    }
};