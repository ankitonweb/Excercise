
#include <iostream>
 struct ListNode {
    int val;
    ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
  };
 


class Solution {
public:
    //Iterative aaproach 
   /* ListNode* reverseList(ListNode* head) {
        ListNode* prev =NULL;
        ListNode* curr = head;
        
        while( curr != NULL)
        {
             ListNode* tmp = curr->next;
             curr->next    = prev;
             prev = curr;
             curr = tmp;
             
             
                       
        }
        head = prev;
        
        return head;
        
        
    }
    */
    // Recursive
    ListNode* reverseList(ListNode* curr) {
       if( curr == NULL || curr->next == NULL)
        return curr;
       ListNode *head = reverseList(curr->next);
       curr->next->next = curr;
       curr->next = NULL;       
       return head; 
    }
};

int main()
{
    
}