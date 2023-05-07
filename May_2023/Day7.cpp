/*  Question: Find th Longest Valid Obstacle Course at Each Position
    Source: https://leetcode.com/problems/find-the-longest-valid-obstacle-course-at-each-position/
    
    CODE:                                                                                         */

class Solution 
{
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) 
    {
        vector<int> a;
        vector<int> res;
        for (auto x : obstacles)
        {
            int idx = upper_bound(a.begin(), a.end(), x) - a.begin();
            if (idx == a.size())
                a.push_back(x);
            else
                a[idx] = x;
            res.push_back(idx + 1);
        }
        return res;
    }
};
