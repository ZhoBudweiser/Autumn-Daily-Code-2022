#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minOperations(vector<string>& logs) {
        int n = logs.size();
        int ans = 0;
        for (int i = 0; i < n; i++) {
            string s = logs[i];
            if (s[0] == '.' && s[1] == '.') {
                if (ans != 0) {
                    ans--;
                }
            } else if (s[0] == '.' && s[1] == '/') {
                continue;
            } else {
                ans++;
            }
        }

        return ans;
    }
};