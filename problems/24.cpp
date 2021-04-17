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
    ListNode* swapPairs(ListNode* head) {
        ListNode* left_prev = NULL;
        ListNode* left = head;
        ListNode* right = left ? left->next : NULL;
        ListNode* right_next = right ? right->next : NULL;
        while (left && right) {
            if (left_prev)
                left_prev->next = right;
            else {
                head = right;
            }
            right->next = left;
            left->next = right_next;
            left_prev = left;
            left = left_prev->next;
            right = left ? left->next : NULL;
            right_next = right ? right->next : NULL;
        }
        return head;
    }
};