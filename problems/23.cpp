#include <bits/stdc++.h>
using namespace std;
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};
class Solution {
   public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        auto cmp = [&](const pair<int, int>& a, const pair<int, int>& b) { return a.first > b.first; };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> pq(cmp);
        for (int i = 0; i < lists.size(); i++) {
            if (lists[i]) pq.push({lists[i]->val, i});
        }
        ListNode* head = NULL;
        ListNode* tail = NULL;
        while (!pq.empty()) {
            int index = pq.top().second;
            ListNode* node = new ListNode(pq.top().first);
            if (!head) {
                head = node;
                tail = head;
            } else {
                tail->next = node;
                tail = tail->next;
            }
            pq.pop();
            lists[index] = lists[index]->next;
            if (lists[index]) pq.push({lists[index]->val, index});
        }
        return head;
    }
};