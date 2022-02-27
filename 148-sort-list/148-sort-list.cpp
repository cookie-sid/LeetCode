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
    ListNode* sortList(ListNode* head) {
        
        if(head == NULL)
            return head;
        
        ListNode* start = head;
        vector<int> vals;
        while(start -> next != NULL) {
            vals.push_back(start -> val);
            start = start -> next;
        }
        vals.push_back(start -> val);
        sort(vals.begin(),vals.end());
        int i = 0;
        ListNode* begin = head;
        while(begin -> next != NULL) {
            begin -> val = vals[i];
            i++;
            begin = begin -> next;
        }
        begin -> val = vals[i];
        return head;
    }
};