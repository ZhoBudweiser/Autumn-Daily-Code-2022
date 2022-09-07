#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string reorderSpaces(string text) {
        int count = 0;
        int n = text.size();
        vector<string> sVector;
        string s = "";
        bool isChar = true;

        if (n == 1) {
            return text;
        }

        while (count < n && text[count] == ' ') {
            count++;
        }
        // cout << count << endl;
        for (int i = count; i < n; i++) {
            if (text[i] == ' ') {
                count++;
                isChar = false;
                continue;
            }
            if (!isChar) {
                sVector.emplace_back(s);
                s = "";
                isChar = true;
            }
            s += text[i];
            // cout << s << endl;
        }
        sVector.emplace_back(s);

        int sz = sVector.size();
        int space, remain;
        if (sz != 1) {
            space = count / (sz-1);
            remain = count % (sz-1);
        } else {
            space = 0;
            remain = count;
        }
        string res = "";
        cout << sz << " " << count << " " << space << " " << remain << endl;
        for (int i = 0; i < sz; i++) {
            res += sVector[i];
            for (int j = 0; i != sz-1 && j < space; j++) {
                res += " ";
            }
        }
        for (int i = 0; i < remain; i++) {
            res += " ";
        }

        return res;
    }
};