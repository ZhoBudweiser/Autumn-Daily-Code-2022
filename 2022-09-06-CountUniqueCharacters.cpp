#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int uniqueLetterString(string s) {
        unordered_map<char, vector<int>> index;
        int n = s.size();
        for (int i = 0; i < n; i++) {
            index[s[i]].emplace_back(i);
        }
        int res = 0;
        for (unordered_map<char, vector<int>>::iterator it = index.begin(); it != index.end(); it++) {
            vector<int> arr = it->second;
            arr.insert(arr.begin(),-1);
            arr.emplace_back(s.size());
            for (int i = 1; i < arr.size()-1; i++) {
                res += (arr[i]-arr[i-1]) * (arr[i+1]-arr[i]);
            }
        }
        return res;
    }
};