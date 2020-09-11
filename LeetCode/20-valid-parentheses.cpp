// Solution
// O(N): Time
// O(N): Space
class Solution
{
public:
    bool isValid(string s)
    {
        unordered_map<char, char> m = {{')', '('}, {'}', '{'}, {']', '['}};
        stack<char> st;
        for (const char& c : s)
        {
            if (c == '(' or c == '{' or c == '[')
            {
                st.push(c);
            }
            else if (c == ')' or c == '}' or c == ']')
            {
                if (st.empty() or (st.top() != m[c]))
                {
                    return false;
                }
                st.pop();
            }
            else
            {
                return false;
            }
        }
        return st.empty();
    }
};