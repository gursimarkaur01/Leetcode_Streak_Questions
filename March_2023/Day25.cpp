/*  Question: Count Unreachable Pairs Of Nodes in an Undirected Graph
    Source: https://leetcode.com/problems/count-unreachable-pairs-of-nodes-in-an-undirected-graph/

    CODE:                                                                                           */

class Solution {
public:
    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<vector<int>> neighbors(n);
        for (auto edge: edges) {
            neighbors[edge[0]].push_back(edge[1]);
            neighbors[edge[1]].push_back(edge[0]);
        }
        vector<bool> visited(n);
        long long sum = 0, squaresum = 0;
        for (int i = 0; i < n; i++){
            if (!visited[i]) {
                long long ans = (long long) dfs(i, neighbors, visited);
                squaresum += ans * ans;
                sum += ans;
            }
        }
        return (sum * sum - squaresum) / 2;
    }
private:
    int dfs(int n, vector<vector<int>>& neighbors, vector<bool>& visited) {
        visited[n] = true;
        int ans = 1;
        for (auto neighbor: neighbors[n]) {
            if (!visited[neighbor]) {
                ans += dfs(neighbor, neighbors, visited);
            }
        }
        return ans;
    }
};
