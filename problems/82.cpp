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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* cur = head;
        while (cur) {
            ListNode* next = cur->next;
            if (next && next->val == cur->val) {
                while (next && next->val == cur->val) {
                    next = next->next;
                }
                if (prev) prev->next = NULL;
            } else {
                if (!prev) {
                    head = cur;
                } else {
                    prev->next = cur;
                }
                prev = cur;
            }
            cur = next;
        }
        if (!prev) head = NULL;
        return head;
    }
};