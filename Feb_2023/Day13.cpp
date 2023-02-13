/* Question: Count Odd Numbers in an Interval
   Source: https://leetcode.com/problems/count-odd-numbers-in-an-interval-range                                                                                        
 
 CODE:                                                                                               */
class Solution {
public:
    int countOdds(int low, int high) {
        int count = 0;
        for(int i = low; i <= high; i++ ){
            if(i%2 != 0){
                count++;
            }
        }
        return count;
    }
};
