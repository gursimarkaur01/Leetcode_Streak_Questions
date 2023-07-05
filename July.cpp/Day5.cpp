/*  Question:  Longest Subarray of 1s After Deleting One Element
    Source: https://leetcode.com/problems/longest-subarray-of-1s-after-deleting-one-element/

    CODE:                                                                                   */

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        int left = 0;
        int zeros = 0;
        int ans = 0;
        for (int right = 0; right < n; right++) {
            if (nums[right] == 0) {
                zeros++;
            }
            while (zeros > 1) {
                if (nums[left] == 0) {
                    zeros--;
                }
                left++;
            }
            ans = max(ans, right - left + 1 - zeros);
        }
        return (ans == n) ? ans - 1 : ans;
    }
};
