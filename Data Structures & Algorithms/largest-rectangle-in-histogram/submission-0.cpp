class Solution {
public:
    int largestRectangleArea(vector<int>& h) {
        /* Problem:
           Find max rectangle in histogram.
           Clarify: heights >=0, n up to 10^5.
           Edge: empty -> 0, all same -> n*h.
           
           Brute force: O(n^2), check minHeight for all ranges.
           Too slow.
           
           Optimized: Use stack (monotonic inc).
           Idea: when bar smaller -> pop till stack valid,
           compute area with popped height as min.
           
           Time: O(n), each bar pushed/popped once.
           Space: O(n) stack.
           
           Example:
           h=[2,1,5,6,2,3]
           -> max=10 (5*2).
        */
        h.push_back(0); // sentinel
        stack<int> st; int maxA=0;
        for(int i=0;i<h.size();i++){
            while(!st.empty() && h[st.top()]>h[i]){
                int ht=h[st.top()]; st.pop();
                int l=st.empty()?0:st.top()+1;
                maxA=max(maxA,ht*(i-l));
            }
            st.push(i);
        }
        return maxA;
    }
};
