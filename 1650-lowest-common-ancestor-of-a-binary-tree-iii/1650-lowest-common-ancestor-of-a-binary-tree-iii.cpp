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
        set<Node*> s;
        s.insert(p);
        while(p -> parent != NULL) {
            s.insert(p);
            p = p -> parent;
        }
        if(s.count(q) == 1) {
            return q;
        }
        while(q -> parent != NULL) {
            if(s.count(q -> parent) == 1) {
                return q -> parent;
            }
            q = q-> parent;
        }
        return q;
    }
};