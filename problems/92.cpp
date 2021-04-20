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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* myhead = NULL;
        ListNode* prev = NULL;
        ListNode* cur = head;
        int index = 1;
        while (cur && index < left) {
            if (!myhead) myhead = cur;
            prev = cur;
            cur = cur->next;
            index++;
        }
        ListNode* reverse_prev = prev;
        ListNode* reverse_tail = cur;
        while (cur && index <= right) {
            ListNode* next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
            index++;
        }
        if (!myhead) myhead = cur;
        if (reverse_prev) reverse_prev->next = prev;
        if (reverse_tail) reverse_tail->next = cur;
        return myhead;
    }
};