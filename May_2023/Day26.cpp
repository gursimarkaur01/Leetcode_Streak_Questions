/*  Question: Stone Game II
    Source: https://leetcode.com/problems/stone-game-ii/
    
    CODE:                                                 */

class Solution {
public:
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
        vector<int> prefixSum(n + 1, 0);
        for (int i = n - 1; i >= 0; --i) {
            prefixSum[i] = prefixSum[i + 1] + piles[i];
        }
        for (int i = n - 1; i >= 0; --i) {
            for (int m = 1; m <= n; ++m) {
                if (i + 2 * m >= n) {
                    dp[i][m] = prefixSum[i];
                } else {
                    for (int x = 1; x <= 2 * m; ++x) {
                        dp[i][m] = max(dp[i][m], prefixSum[i] - dp[i + x][max(m, x)]);
                    }
                }
            }
        }
        return dp[0][1]; 
    }
};
