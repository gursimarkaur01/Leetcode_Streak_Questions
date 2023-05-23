/*  Question: Kth Largest Element in a Stream
    Source: https://leetcode.com/problems/kth-largest-element-in-a-stream/
    
    CODE:                                                         */

class KthLargest {
public:
    priority_queue<int,vector<int>,greater<int>> pq;
    int sz;
    KthLargest(int k, vector<int>& nums) {
         sz = k;
        for(int i=0;i<nums.size();i++){
            pq.push(nums[i]);
        }
    }
    int add(int val) {   
       pq.push(val);
        while(pq.size()>sz){
            pq.pop();
        }
        return pq.top();
    }
};
