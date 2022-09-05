#include<bits/stdc++.h>
using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution {
public:
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        DFS(root);
        return {res.begin(), res.end()};
    }
    string DFS(TreeNode* T) {
        if (!T) {
            return "";
        }
        string str = to_string(T->val) + "(" + DFS(T->left) + ")(" + DFS(T->right) + ")";
        auto it = seen.find(str);
        if (it != seen.end()) {
            res.insert(it->second);
        } else {
            seen[str] = T;
        }
        return str;
    }

private:
    unordered_map<string, TreeNode*> seen;
    unordered_set<TreeNode*> res;
};