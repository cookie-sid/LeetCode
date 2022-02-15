/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* parent;
};
*/

class Solution {
public:
    Node* lowestCommonAncestor(Node* p, Node * q) {
        unordered_map<Node*,int> m;
        m[p] = 1;
        while(p -> parent != NULL) {
            m[p->parent] = 1;
            p = p -> parent;
        }
        if(m[q] == 1) {
            return q;
        }
        while(q -> parent != NULL) {
            if(m[q -> parent] == 1) {
                return q -> parent;
            }
            q = q-> parent;
        }
        return q;
    }
};