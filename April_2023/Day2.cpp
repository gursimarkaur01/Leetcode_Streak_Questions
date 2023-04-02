/*  Question: Successful Pairs of Spells and Potions
    Source: https://leetcode.com/problems/successful-pairs-of-spells-and-potions/

    CODE:                                                                           */

class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        vector<int> numPairs(spells.size(), 0);
        for(int i = 0; i < spells.size(); i++) { 
            int spell = spells[i];
            int count = 0;
            for(int potion: potions) { 
                long long pair = (long long)potion * (long long)spell;
                if(pair >= success) count++;
            }
            numPairs[i] = count;
        }
        return numPairs;
    }
};
