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
    ListNode* sortList(ListNode* head) {
        if(head==NULL || head->next==NULL){
            return head;
        }
        ListNode *mid=MidNode(head);
        ListNode *list1=head;
        ListNode *list2=mid->next;
        mid->next=NULL;
        list1=sortList(list1);
        list2=sortList(list2);
        ListNode *ans=Merge(list1,list2);
        return ans;
    }
    ListNode *MidNode(ListNode *head){
        ListNode *slow=head;
        ListNode *fast=head->next;
        while(fast!=NULL && fast->next!=NULL){
            fast=fast->next->next;
            slow=slow->next;
        }
        return slow;
    }
    ListNode *Merge(ListNode *list1, ListNode *list2){
        ListNode *ptr=new ListNode();
        if(list1==NULL){
            return list2;
        }
        if(list2==NULL){
            return list1;
        }
        if(list1->val<list2->val){
            ptr=list1;
            ptr->next=Merge(list1->next,list2);
        }
        else{
            ptr=list2;
            ptr->next=Merge(list1,list2->next);
        }
        return ptr;
    }
};