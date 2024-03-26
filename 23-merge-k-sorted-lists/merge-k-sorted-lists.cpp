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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0) {
            return NULL;
        }
        ListNode* dummyHead = new ListNode(-1);
        ListNode* temp = dummyHead;
        priority_queue<pair<int, ListNode*>, vector<pair<int, ListNode*>>, greater<pair<int, ListNode*>>> pq;
        for(int i=0;i<lists.size();i++){
            if(lists[i] != NULL) {
                pq.push({lists[i]->val, lists[i]});
            }
        }  
        while(!pq.empty()){
            ListNode* minNode = pq.top().second;
            pq.pop();
            if(minNode->next != NULL) {
                pq.push({minNode->next->val, minNode->next});
            }
            temp->next = minNode;
            temp = temp->next;
        }
        return dummyHead->next;
    }
};