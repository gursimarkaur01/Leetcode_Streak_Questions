/*  Question: Symmetric Tree
    Source: https://leetcode.com/problems/symmetric-tree/

    CODE:                                                                       */

class Solution {
public:
    bool symmetric(TreeNode *lst,TreeNode *rst){
        if(lst==NULL && rst==NULL)return true;
        if(lst==NULL || rst==NULL)return false;
        if(lst->val!=rst->val)return false;
        return symmetric(lst->left,rst->right)&&symmetric(lst->right,rst->left);
        
    }
    bool isSymmetric(TreeNode* root) {
        if(!root || root->right==NULL && root->left==NULL)return true;
        return symmetric(root->left,root->right);
        
    }
};
