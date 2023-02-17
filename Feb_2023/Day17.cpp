/*  Question: Minimum Distance Between BST Nodes
    Source: https://leetcode.com/problems/minimum-distance-between-bst-nodes/

    CODE:                                                                         */
class Solution {
public:
    vector<int> inorderNodes;                 // List to store the tree nodes in the inorder traversal.
    void inorderTraversal(TreeNode* root) {
        if (root == NULL) {
            return;
        }
        inorderTraversal(root->left);           // Store the nodes in the list.
        inorderNodes.push_back(root->val);
        inorderTraversal(root->right);
    }    
    int minDiffInBST(TreeNode* root) {
        inorderTraversal(root);
        int minDistance = INT_MAX;              // Find the diff between every two consecutive values in the list.
        for (int i = 1; i < inorderNodes.size(); i++) {
            minDistance = min(minDistance, inorderNodes[i] - inorderNodes[i - 1]);
        }
        return minDistance;
    }
};
