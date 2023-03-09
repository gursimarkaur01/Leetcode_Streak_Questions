/*  Question: Linked List Cycle II
    Source: https://leetcode.com/problems/linked-list-cycle-ii/

    CODE:                                                                                   */

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(!head||!head->next)return nullptr;
        ListNode*hare=head,*tor=head;
        do{
            hare=hare->next->next;
            tor=tor->next;
        }while(tor!=hare&&hare&&hare->next);
        if(!hare||!hare->next){
            return nullptr;
        }
        else{
            tor=head;
            while(hare!=tor){
                hare=hare->next;
                tor=tor->next;
            }
        }
        return tor;
    }
};
