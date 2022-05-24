#pragma once

#include <string>
#include <stack>

using std::string;
using std::stack;

//O(N)
bool is_valid(const string& str)
{
    char open_1 = '(', close_1 = ')';
    char open_2 = '{', close_2 = '}';
    char open_3 = '[', close_3 = ']';

    stack<char> st;
    for (auto ch : str)
    {
        if (ch == close_1 || ch == close_2 || ch == close_3)
        {
            if (st.empty()) return false;

            if (st.top() == open_1 && ch != close_1)
                return false;

            if (st.top() == open_2 && ch != close_2)
                return false;

            if (st.top() == open_3 && ch != close_3)
                return false;

            st.pop();
            continue;
        }

        st.push(ch);
    }

    return st.empty();
}