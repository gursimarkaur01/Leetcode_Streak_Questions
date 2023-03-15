/*  Question: Check Completeness of a Binary Tree
    Source: https://leetcode.com/problems/check-completeness-of-a-binary-tree/

    CODE:                                                                                 */

class Solution {
public:
    bool isCompleteTree(TreeNode* root) {
        if(!root) return true; 
        queue<TreeNode*>q;
        q.push(root);
        bool nullSeen=false; 

        while(!q.empty()){ 
            int levelSize=q.size(); 
            while(levelSize--){    
                TreeNode* tp=q.front();
                q.pop();
                if(!tp) nullSeen=true;  
                else{
                    if(nullSeen) return false; 
                    q.push(tp->left);
                    q.push(tp->right);
                }
            }
        }
        return true;
    }
};
