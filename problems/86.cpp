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
    ListNode* partition(ListNode* head, int x) {
        ListNode* virtual_head = new ListNode();
        ListNode* small = NULL;
        ListNode* big = NULL;
        ListNode* firstBig = NULL;
        while (head) {
            if (head->val < x) {
                if (small) small->next = head;
                small = head;
                if (!virtual_head->next) virtual_head->next = small;
            } else {
                if (big) big->next = head;
                big = head;
                if (!firstBig) firstBig = head;
            }
            head = head->next;
        }
        if (big) big->next = NULL;
        if (small) small->next = firstBig;
        if (!virtual_head->next) virtual_head->next = firstBig;
        return virtual_head->next;
    }
};