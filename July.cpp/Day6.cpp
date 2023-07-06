/*  Question:  Minimum Size Subarray Sum
    Source:  https://leetcode.com/problems/minimum-size-subarray-sum/

    CODE:                                                            */
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
         int l = 0, r = 0, res = std::numeric_limits<int>::max(), s = 0;
        for (r = 0; r < nums.size(); r++) {
            s += nums[r];
            while (s >= target) {
                s -= nums[l];
                res = std::min(res, r - l + 1);
                l++;
            }
        }
        if (res == std::numeric_limits<int>::max())
            return 0;
        return res;
    }
};
