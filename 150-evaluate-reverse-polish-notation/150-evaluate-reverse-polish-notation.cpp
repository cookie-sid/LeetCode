class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        for(auto x : tokens) {
            if(x != "+" and x != "-" and x != "/" and x != "*") {
                s.push(stoi(x));
            }
            else {
                int op2 = s.top();
                s.pop();
                int op1 = s.top();
                s.pop();
                if(x == "+")
                    s.push(op1 + op2);
                else if(x == "-")
                    s.push(op1 - op2);
                else if(x == "*")
                    s.push(op1 * op2);
                else
                    s.push(op1 / op2);
            }
        }
        return s.top();
    }
};