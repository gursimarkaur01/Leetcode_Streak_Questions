/*   Question: No of Zero Filled Subarrays
     Source: https://leetcode.com/problems/number-of-zero-filled-subarrays/
     
     CODE:                                                                                                */
     class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        int n=nums.size();
        long long ans=0;
        long long count=0;
        for(int i=0;i<n;++i){
        if(nums[i]==0){
          count++;
        }else{
           
            if(count){
                 ans+=(count*(count+1))/2;
            }
          count=0;   
        }
        }
      if(count!=0){
        ans+=(count*(count+1))/2;
      }
        return ans;
    }
};
