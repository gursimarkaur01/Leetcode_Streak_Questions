/*  Question: Maximum Number of Vowels in a Substring of Given Length 
    Source: https://leetcode.com/problems/maximum-number-of-vowels-in-a-substring-of-given-length/
    
    CODE:                                                                                              */

class Solution {
public:
    int maxVowels(string s, int k) {
        unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u'};
        int max_count = 0;
        int count = 0;
        for (int i = 0; i < s.length(); i++) {
            if (i >= k && vowels.count(s[i-k])) {
                count--;
            }
            if (vowels.count(s[i])) {
                count++;
            }
            max_count = max(max_count, count);
        }
        return max_count;
    }
};
