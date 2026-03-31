class Solution {
public:
    string convertToTitle(int columnNumber) {
       unordered_map<int,char> map;

       for(int i = 1 ; i <= 26 ; i++) 
       {
         map[i] = 'A' + i -1;
       }


       stack<char> st;

       while( columnNumber > 0)
       {
        columnNumber--;
        int rem = columnNumber %26 + 1;
        st.push(map[rem]);
        columnNumber = columnNumber/26;


       }

     string result;
     while (!st.empty()) {
        result += st.top();  // add char to string
        st.pop();
    }

     return result;
    }
};