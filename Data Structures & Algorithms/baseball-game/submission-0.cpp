class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> st;
        int sum = 0;

        for (string &op : operations) {
            if (op == "+") {
                int top1 = st.top(); st.pop();
                int top2 = st.top();
                st.push(top1); // put back top1
                st.push(top1 + top2);
                sum += top1 + top2;
            }
            else if (op == "D") {
                int doubled = 2 * st.top();
                st.push(doubled);
                sum += doubled;
            }
            else if (op == "C") {
                sum -= st.top();
                st.pop();
            }
            else {
                int num = stoi(op);
                st.push(num);
                sum += num;
            }
        }

        return sum;
    }
};
