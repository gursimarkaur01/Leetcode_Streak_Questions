/*  Question: Single Element in a Sorted Array 
    Source: https://leetcode.com/problems/single-element-in-a-sorted-array/
    
    CODE:                                                                         */

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
    int left=0,right=nums.size()-1;
    while(left<right && left>=0 && right<=nums.size()-1)
    {
        cout<<"left : "<<left<<" right : "<<right<<endl;
        int middleIndex = (left+right)/2;
        if(middleIndex%2 == 0){
            if(nums[middleIndex] == nums[middleIndex+1])
            {
                left = middleIndex+1; 
            }
            else{
                right = middleIndex;
            }
        }
        else{
            if(nums[middleIndex] == nums[middleIndex-1])
            {
                left = middleIndex+1;
            }
            else{
                right = middleIndex;
            }
        }
    }
    return nums[right];
} 

};
