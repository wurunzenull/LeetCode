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
    ListNode* rotateRight(ListNode* head, int k) {
        vector<ListNode*> myList;
        ListNode* temp = head;
        while (temp) {
            myList.push_back(temp);
            temp = temp->next;
        }
        int n = myList.size();
        if (n == 0) return head;
        for (int i = 0; i < k % n; i++) {
            int tail_prev = (n - 2 - i) % n;
            int tail = (n - 1 - i) % n;
            int tail_next = (n - i) % n;
            myList[tail_prev]->next = NULL;
            myList[tail]->next = myList[tail_next];
            head = myList[tail];
        }
        return head;
    }
};