/*  Question: Average Salary Excluding the Minimum and Maximum Salary
     Source: https://leetcode.com/problems/average-salary-excluding-the-minimum-and-maximum-salary/
     
     CODE:                                                                                           */

class Solution {
public:
    double average(vector<int>& salary) {
        int max = salary[0];  
        int min = salary[0];
        int sum = 0;
        for (int i = 0; i < salary.size(); i++) { 
            if (salary[i] > max) {
                max = salary[i];
            }
            if (salary[i] < min) {
                min = salary[i];
            }
            sum += salary[i];
        }
        return (sum - max - min) / (salary.size() - 2.0);    
    }
};
