/* Question: Minimum Fuel Cost to Report to the Capital
   Source: https://leetcode.com/problems/minimum-fuel-cost-to-report-to-the-capital/

   CODE:                                                                                                     */

class Solution {
public:
    long long fuel;

    long long dfs(int node, int parent, vector<vector<int>>& adj, int& seats) { 
        int representatives = 1;                                                        // The node itself has one representative.
        for (auto& child : adj[node]) {
            if (child != parent) {
                representatives += dfs(child, node, adj, seats);                      // Add count of representatives in each child subtree to the parent subtree.
            }
        }

        if (node != 0) {
            fuel += ceil((double)representatives / seats);                           // Count the fuel it takes to move to the parent node.
                                                                                     // Root node does not have any parent so we ignore it.
        }
        return representatives;
    }
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        int n = roads.size() + 1;
        vector<vector<int>> adj(n);
        for (auto& road : roads) {
            adj[road[0]].push_back(road[1]);
            adj[road[1]].push_back(road[0]);
        }
        dfs(0, -1, adj, seats);
        return fuel;
    }
};
