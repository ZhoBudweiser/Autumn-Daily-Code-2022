#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minAddToMakeValid(string s) {
        int n = s.size();
        stack<char> st;
        for (int i = 0; i < n; i++) {
            char ch = s[i];
            if (ch == '(') {
                st.push(ch);
            } else if (ch == ')') {
                if (st.size()) {
                    char tp = st.top();
                    if (tp == '(') {
                        st.pop();
                    } else {
                        st.push(ch);
                    }
                } else {
                    st.push(ch);
                }
            }
        }
        return st.size();
    }
};