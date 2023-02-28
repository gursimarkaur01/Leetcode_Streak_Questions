/*  Question: Find Duplicate Subtree
    Source: https://leetcode.com/problems/find-duplicate-subtrees/
  
    CODE:                                                                                         */
class Solution {
public:
    
    ;
    string f(TreeNode* root,vector<TreeNode*>&ans, map<string,int> &mp){
        if(!root) return "%";
        string l = f(root->left,ans,mp);
        string r = f(root->right,ans,mp);
        string s = to_string(root->val) +"%"+l+"%"+r;
        if(mp[s]==1){
            ans.push_back(root);
        }
        mp[s]++;
        return s;
    }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        vector<TreeNode*> ans;
        map<string,int> mp;
        if(!root) return ans;
        f(root,ans,mp);
        return ans;
    }
};
