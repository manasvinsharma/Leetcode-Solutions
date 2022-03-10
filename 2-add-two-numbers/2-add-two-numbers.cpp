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
    ListNode* solve(ListNode* l1, ListNode* l2, int carry)
    {
        // if both lists reached to end
        if(!l1 && !l2)
        {
            if(carry!=0)
            {
                return new ListNode(carry);
            }
            else
            {
                return NULL;
            }
        }
        
        // find the sum 
        int sum = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + carry;
        int nodevalue;
        
        // if sum is more than 9 than there will be carry also
        if(sum>9)
        {
            nodevalue = sum%10;
            carry = sum/10;
        }
        else
        {
            nodevalue = sum;
            carry=0;
        }
        
        // create a new node which is our answer linklist
        ListNode* newnode = new ListNode(nodevalue);
        
        newnode->next = solve(l1 ? l1->next : l1, l2 ? l2->next : l2, carry);
        
        return newnode;
    }
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry=0;
        return solve(l1,l2,carry);
    }
};