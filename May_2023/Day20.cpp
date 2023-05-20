/*  Question: Evaluate Division
    Source: https://leetcode.com/problems/evaluate-division/
    
    CODE:                                                     */

class Solution {
public:
    double dfs(unordered_map<string, vector<pair<string, double>>>&adj, unordered_map<string, int>&visited, string& target, string curr)
    {
        if (!adj.count(curr)) return INT_MAX;
        if (curr == target) return 1;
        for (pair<string, double>& adjNode : adj[curr])
        {
            if (visited[adjNode.first]) continue;
            visited[adjNode.first] = 1;
            double currCost = adjNode.second;
            double nextCost = dfs(adj, visited, target, adjNode.first);
            visited[adjNode.first] = 0;
            if (nextCost != INT_MAX) 
                return (nextCost * currCost);
        }
        return INT_MAX;
    }
    vector<double>calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) 
    {
        unordered_map<string, vector<pair<string, double>>>adj;
        for (int i = 0; i < equations.size(); i++)
        {
            adj[equations[i][0]].push_back({equations[i][1], values[i]});
            adj[equations[i][1]].push_back({equations[i][0], (1.00 / values[i])});
        }
        vector<double>ans;
        unordered_map<string, int>visited;
        for (vector<string>& query : queries)
        {
            double cost = cost = dfs(adj, visited, query[1], query[0]);
            ans.push_back(cost == INT_MAX? -1 : cost);
        }
        return ans;
    }
};
