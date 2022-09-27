#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool CheckPermutation(string s1, string s2) {
        int n1 = s1.size();
        int n2 = s2.size();
        if (n1 != n2) {
            return false;
        }
        map<char, int> mp;
        for (int i = 0; i < n1; i++) {
            mp[s1[i]]++;
        }
        for (int i = 0; i < n1; i++) {
            mp[s2[i]]--;
            if (mp[s2[i]] < 0) {
                return false;
            }
        }
        return true;
    }
};