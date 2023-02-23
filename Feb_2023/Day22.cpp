/*  Question: IPO
    Source: https://leetcode.com/problems/ipo/
  
  CODE:                                                   */
class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        vector<pair<int, int>> projects(profits.size());                                  // Sort projects in order of capital (least capital -> most capital)
        for (size_t i = 0; i < profits.size(); i++) {
            projects[i] = {capital[i], profits[i]};
        }
        sort(projects.begin(), projects.end());
        priority_queue<int> best_profit;                                                   // Keep track of highest profit project in priority queue
        for (const auto& [cost, profit]: projects) {
            while (!best_profit.empty() && w < cost && k--) {                             // If we can't afford this project, take highest profit until we can
                w += best_profit.top(); best_profit.pop();
            }
            if (!k || w < cost) return w;                                                // No more projects can be conducted - return current capital
            best_profit.push(profit);                                                    // Add project to priority queue
        }
        while (k-- && !best_profit.empty()) {                                           // All remaining projects are affordable - add the best ones
            w += best_profit.top();
            best_profit.pop();
        }
        return w;
    }
};
