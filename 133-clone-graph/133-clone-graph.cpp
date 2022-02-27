/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    
    Node* cloneGraph(Node* node) {
        if(node == NULL) {
            return node;
        }
        queue<Node*> q;
        map<int,pair<bool,Node*>> m;
        Node* start = new Node(node -> val, node -> neighbors);
        m[node -> val] = make_pair(true,start);
        for(auto x : start -> neighbors) {
            q.push(x);
        }
        while(!q.empty()) {
            int currsize = q.size();
            while(currsize > 0) {
                Node *temp = q.front();
                if(m[temp -> val].first == true) {
                    q.pop();
                    currsize--;
                    continue;
                }
                Node* start = new Node(q.front() -> val, q.front() -> neighbors);
                m[start -> val] = make_pair(true,start);
                for(auto x : start -> neighbors) {
                    q.push(x);
                }
                q.pop();
                currsize--;
            }
        }
        for(auto x : m) {
            Node* temp =  m[x.first].second;
            vector<Node*> neighbours = temp -> neighbors;
            for(int i = 0; i < neighbours.size(); i++) {
                neighbours[i] = m[neighbours[i] -> val].second;
            }
            m[x.first].second -> neighbors = neighbours;
        }
        return start;
    }
    
};