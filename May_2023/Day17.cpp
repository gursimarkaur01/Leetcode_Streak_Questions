/*  Question: Maximum Twin Sum of a Linked List
    Source: https://leetcode.com/problems/maximum-twin-sum-of-a-linked-list/
    
    CODE:                                                                     */

class Solution {
    public:
     int pairSum(ListNode* head){
        ListNode* slow = head;
        ListNode* fast = head;
        int maxVal = 0;
        while(fast && fast -> next){
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        ListNode *nextNode, *prev = NULL;
        while (slow){
            nextNode = slow->next;
            slow->next = prev;
            prev = slow;
            slow = nextNode;
        }
        while(prev){
            maxVal = max(maxVal, head -> val + prev -> val);
            prev = prev -> next;
            head = head -> next;
        }
        return maxVal;
    }
};
