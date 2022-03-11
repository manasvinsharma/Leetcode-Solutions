/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int getsize(ListNode* head)
    {
        if(head==NULL)
            return 0;
        
        int s=0;
        while(head)
        {
            head=head->next;
            s++;
        }
        return s;
    }
    
    ListNode* rotateRight(ListNode* head, int k) {
        // base case
        if(head==NULL || head->next==NULL)
            return head;

        ListNode* tail=head;
        ListNode* ans=head;
        ListNode* lastnode=head;
        ListNode* secondlastnode=head;
        int sz = getsize(head);    
        k=(k%sz);
        
        int newlastnode = sz-k;
        
        if(newlastnode==sz)
            return head;
        
        while(newlastnode)
        {
            secondlastnode=lastnode;
            lastnode=lastnode->next;
            newlastnode--;
        }
        
        
        while(head)
        {
            if(head && head->next==NULL)
                tail=head;
            
            head=head->next;
        }
        
        secondlastnode->next=NULL;
        tail->next=ans;
        return lastnode;
    }
};