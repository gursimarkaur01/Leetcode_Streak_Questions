/*  Question: Longest Cycle ina 
    Source: https://leetcode.com/problems/longest-cycle-in-a-graph/

    CODE:                                                                                             */
class Solution {
public:
    int longestCycle(vector<int> &edges) {
        int res = -1;
        for (int i = 0, len = edges.size(), j, k = -2000000000, curr, prev; i < len; i++) {
            prev = i, curr = edges[i];
            if (curr < 0) continue;
            j = k;
            while (curr >= 0) {
                edges[prev] = j--;
                prev = curr;
                curr = edges[curr];
            }
            if (curr != -1) res = max(res, curr - j);
            k += 10000;
        }
        return res;
    }
};
