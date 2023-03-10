/* Question: Maximum Depth of Binary Tree
   Source: https://leetcode.com/problems/maximum-depth-of-binary-tree/

  CODE:                                                                                           */
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root == NULL) return 0;
        int left = maxDepth(root->left);
        int right = maxDepth(root->right);
        return max(left, right) + 1;
    }
};
