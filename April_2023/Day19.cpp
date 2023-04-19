/*  Question: Longest Zigzag Path in a Binary Tree
    Source: https://leetcode.com/problems/longest-zigzag-path-in-a-binary-tree/
    
    CODE:                                                                           */

class Solution {
public:
    pair<int,int> helper(TreeNode* root, int &ans) {
        if(root == NULL) return {0,0};
        pair<int,int> l = helper(root->left,ans);
        ans = max(ans,1+l.second);
        pair<int,int> r = helper(root->right,ans);
        ans = max(ans,1+r.first);
        return {1+l.second,1+r.first};
    }
    int longestZigZag(TreeNode* root) {
        int ans = 0;
        helper(root,ans);
        return ans-1;
    }
};
