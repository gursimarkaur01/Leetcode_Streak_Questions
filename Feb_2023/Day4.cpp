//Question: Permutation in String
//Source: https://leetcode.com/problems/permutation-in-string

class Solution {
public:
    bool checkInclusion(string s1, string s2) 
    {
        // storing the letters occurance places in s1
        int count1[26] = {0};
        for(int i = 0; i < s1.size(); i++) count1[s1[i] - 'a']++;
        
        for(int i = 0; i < s2.size(); i++)
        {
            bool flag = true;
          
            // take out current substring from s2 of size s1 because we need to check permutation of s1
            string str = s2.substr(i, s1.size());         

            // storing the letters occurance places in substring of s2
            int count2[26] = {0};
            for(int j = 0; j < str.size(); j++) count2[str[j] - 'a']++;
            
            // if all the letters ocuurences are same in substring and s1 then it means there is permutation
            for(int idx = 0; idx < 26; idx++)
            {
                // if no match, no permutation
                if(count1[idx] != count2[idx])
                {
                    flag = false;
                    break;
                }
            }    
            // if we got true at any point of time return true
            if(flag) return true;           
        }
        return false;
    }
};
