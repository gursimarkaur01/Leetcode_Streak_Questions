/*  Question:   Minimum Depth of Binary Tree
    Source:  https://leetcode.com/problems/minimum-depth-of-binary-tree/

    CODE:                                                                */

class Solution {
public:
    int minDepth(TreeNode* root) {
        if(root == NULL){
            return 0;
        }
        int left = minDepth(root->left);
        int right = minDepth(root->right);
        if(root->left && root->right){
            return min(left+1, right+1);
        }
        return max(left+1, right+1);
    }
};
