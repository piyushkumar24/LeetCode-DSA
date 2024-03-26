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

// class Solution {
// public:
//     ListNode* reverse(ListNode *head){
//         if(head==NULL) {
//             return NULL;
//         }
//         ListNode *prev = NULL;
//         ListNode *curr = head;
//         ListNode *nextNode = NULL;
//         while(curr){
//             nextNode = curr->next;
//             curr->next = prev;
//             prev = curr;
//             curr = nextNode;
//         }
//         return prev;
//     }

//     void merge(ListNode *list1, ListNode *list2){
//         while(list2) {
//             ListNode  *nextNode = list1->next;
//             list1->next = list2;
//             list1 = list2;
//             list2 = nextNode;
//         }
//     }

//     void reorderList(ListNode* head) {
//         if(head==NULL || head->next==NULL){
//             return;
//         } 
//         ListNode *slow = head;
//         ListNode *fast = head;
//         ListNode *prev = head;
//         while(fast!=NULL && fast->next!=NULL){
//             prev = slow;
//             fast = fast->next->next;
//             slow = slow->next;
//         }
//         prev->next = NULL;
//         ListNode *list1 = head;
//         ListNode *list2 = reverse(slow);
//         merge(list1,list2);
//     }
// };



class Solution {
public:
    
    ListNode*middle(ListNode*head){
        ListNode*slow = head;
        ListNode*fast = head;
        while(fast->next!=NULL and fast->next->next!=NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    
    ListNode*reverse(ListNode*head){
        ListNode*curr = head;
        ListNode*prev = NULL;
        ListNode*forw = NULL;
        while(curr){
            forw = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forw;
        }
        return prev;
    }
    
    void reorderList(ListNode* head) {
        if(head==NULL || head->next==NULL){
            return;
        }
        ListNode*mid = middle(head);
        ListNode*k = reverse(mid->next);
        mid->next = NULL;
        ListNode*c1 = head;
        ListNode*c2 = k;
        ListNode*f1 = NULL;
        ListNode*f2 = NULL;
        while(c1!=NULL && c2!=NULL){
            f1 = c1->next;
            f2 = c2->next;
            c1->next = c2;
            c2->next = f1;
            c1 = f1;
            c2 = f2;
        }
    }
};