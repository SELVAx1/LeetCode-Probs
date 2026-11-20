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
        priority_queue<int, vector<int>, greater<int>> pq;
        for(int i = 0; i < lists.size(); i++){
            ListNode* temp = lists[i];
            while(temp){
                pq.push(temp->val);
                temp = temp->next;
            }
        }
        if(pq.empty()) return NULL;
        ListNode* ans = new ListNode(pq.top());
        ListNode* temp = ans;
        pq.pop();
        while(!pq.empty()){
            temp->next = new ListNode(pq.top());
            temp = temp->next;
            pq.pop();
        }
        return ans;
    }
};