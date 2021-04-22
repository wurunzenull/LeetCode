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
    ListNode* insertionSortList(ListNode* head) {
        ListNode* dummyHead = new ListNode(0, head);
        ListNode* sorted = head;
        while (sorted && sorted->next) {
            if (sorted->val <= sorted->next->val) {
                sorted = sorted->next;
                continue;
            }
            ListNode* cur = sorted->next;
            ListNode* prev = dummyHead;
            while (prev->next && prev->next->val < cur->val) prev = prev->next;
            sorted->next = cur->next;
            cur->next = prev->next;
            prev->next = cur;
        }
        return dummyHead->next;
    }
};