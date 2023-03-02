/*  Question: String compression
    Source: https://leetcode.com/problems/string-compression/
    
    CODE:                                                                                         */
class Solution {
public:
    int compress(vector<char>& chars) {
        int ans = 0;
        for (int i = 0; i < chars.size();) {                                           // iterate through input vector using i pointer
            const char letter = chars[i];                                             // current character being compressed
            int count = 0;                                                           // count of consecutive occurrences of letter
            while (i < chars.size() && chars[i] == letter) {                        // count consecutive occurrences of letter in input vector
                ++count;
                ++i;
            chars[ans++] = letter;                                                 // write letter to compressed vector
            if (count > 1) {                                                      // if count is greater than 1, write count as string to compressed vector
                for (const char c : to_string(count)) {                          //convert count to string and iterate over each character in string
                    chars[ans++] = c;
                }
            }
        }
        return ans;                                                               // return length of compressed vector
    }
};
