/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        // edge case
        if(head==NULL)
            return head;

        Node* temp1 = head;
        
        // value will contain the value of current node of given linklist
        int value;
        // nxt will contain the value of next pointer of current node of given linklist
        Node* nxt = NULL;
        // rand will contain the value of random pointer of current node of given linklist
        Node* rand = NULL;
        
        // adding a deep copy node after each given linklist node
        while(temp1)
        {
            nxt = temp1->next;
            rand = temp1->random;
            value = temp1->val;
            
            // creating the deep copy of current node
            Node* newnode = new Node(value);
            newnode->next = nxt;
            newnode->random = rand;
            
            temp1->next = newnode;
            
            // advancing the temp1 by 2 units
            temp1 = newnode->next;
        }
        
        // below code is used so that the random pointer of our deep copy nodes points to other deep copy nodes only & not to the original list nodes.
        Node* secondaryHead = head->next;
        while(secondaryHead)
        {            
            if(secondaryHead->random)
            {
                secondaryHead->random = secondaryHead->random->next;
            }
            else
            {
                secondaryHead->random = NULL;
            }
            
            secondaryHead = secondaryHead->next;
            if(!secondaryHead)
                break;
            
            secondaryHead = secondaryHead->next;
        }
        
        // below code is just used to seperate out the deep copy linklist.
        // And also to transform back the given linklist to its original form(otherwise it will error)
        secondaryHead = head->next;
        Node* ans = head->next;
        while(head)
        {
            head->next = secondaryHead->next;
            if(secondaryHead->next)
            secondaryHead->next = secondaryHead->next->next;
            else
            secondaryHead->next = NULL;
            
            head = head->next;
            secondaryHead = secondaryHead->next;
        }
        return ans;
    }
};