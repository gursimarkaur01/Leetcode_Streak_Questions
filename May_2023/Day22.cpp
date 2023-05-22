/*  Question: Top K Frequency Elements
    Source: https://leetcode.com/problems/top-k-frequent-elements/
    
    CODE:                                                                         */

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> counter;
        for (int num : nums) {
            counter[num]++;
        }
        auto cmp = [](const pair<int, int>& a, const pair<int, int>& b) {
            return a.second > b.second;
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> heap(cmp);
        for (const auto& entry : counter) {
            heap.push(entry);
            if (heap.size() > k) {
                heap.pop();
            }
        }
        vector<int> result;
        while (!heap.empty()) {
            result.push_back(heap.top().first);
            heap.pop();
        }
        return result;
    }
};
