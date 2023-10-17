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
        if(head==NULL){
            return NULL;
        }
        Node *ptr=head;
        Node *curr=head->next;
        while(ptr!=NULL){
            Node *temp=new Node(ptr->val);
            ptr->next=temp;
            temp->next=curr;
            ptr=curr;
            if(curr!=NULL){
                curr=curr->next;
            }
        }
        ptr=head;
        while(ptr!=NULL){
            if(ptr->random!=NULL){
                Node *a=ptr->next;
                a->random=ptr->random->next;
            }
            ptr=ptr->next->next;
        }
        Node *copy=head->next;
        ptr=head;
        curr=head->next;
        while(curr->next!=NULL){
            ptr->next=curr->next;
            curr->next=curr->next->next;
            ptr=ptr->next;
            curr=curr->next;
        }
        ptr->next=NULL;
        return copy;
    }
};