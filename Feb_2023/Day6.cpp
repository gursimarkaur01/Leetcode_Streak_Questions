/*  
Question: Shuffle the array
Source: leetcode.com/problems/shuffle-the-array  
*/

//CODE:

class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> ans;
        
        for(int i =0 ;i < n;i++){
            ans.push_back(nums[i]);
            ans.push_back(nums[i+n]);
        }
        return ans;
    }
};
