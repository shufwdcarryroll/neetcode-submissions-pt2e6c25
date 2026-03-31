class Solution {
public:
    bool isValid(string s) {
       stack<char> st;

       for( char ch : s) 
       {

        if(ch == '(') st.push('(');
        if(ch == '[') st.push('[');
        if(ch == '{') st.push('{');

        if(ch == ')')
        {
            if(st.empty())
             return false;

            char op = st.top();
            st.pop();

            if(op == '(') 
               continue;
            else
               return false;

        }

        if(ch == ']')
        {
            if(st.empty())
             return false;

            char op = st.top();
            st.pop();

            if(op == '[') 
               continue;
            else
               return false;

        }

        if(ch == '}')
        {
            if(st.empty())
             return false;
             
            char op = st.top();
            st.pop();

            if(op == '{') 
               continue;
            else
               return false;

        }


       }

       if(st.empty())
         return true;

    return false;
    }
};