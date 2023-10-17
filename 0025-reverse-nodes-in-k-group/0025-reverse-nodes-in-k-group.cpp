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
    ListNode* reverseKGroup(ListNode* head, int k) {
        int size=0;
        ListNode *temp=head;
        while(temp!=NULL){
            temp=temp->next;
            size++;
        }
        if(head==NULL || head->next==NULL || k==1){
            return head;
        }
        if(size<k){
            return head;
        }
        ListNode *prevptr=NULL;
        ListNode *currptr=head;
        ListNode *nextptr=NULL;
        int count=0;
        while(currptr!=NULL && count<k){
            nextptr=currptr->next;
            currptr->next=prevptr;
            prevptr=currptr;
            currptr=nextptr;
            count++;
        }
        if(nextptr!=NULL){
            head->next=reverseKGroup(nextptr,k);
        }
        return prevptr;
    }
};