/*  Question: Can Make Arithmetic Progression from Sequence
    Source: https://leetcode.com/problems/can-make-arithmetic-progression-from-sequence/
    
    CODE:                                                                               */

class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        sort(begin(arr), end(arr));
        int d = arr[1] - arr[0];
        for (int i = 2; i < arr.size(); ++i) {
            if (arr[i] - arr[i - 1] != d) return false;
        }
        return true; 
    }
};
