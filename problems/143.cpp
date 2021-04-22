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
    void reorderList(ListNode* head) {
        vector<ListNode*> mylist;
        ListNode* temp = head;
        while (temp) {
            mylist.push_back(temp);
            temp = temp->next;
        }
        int left = 0, right = mylist.size() - 1;
        while (left < right - 1) {
            ListNode* temp = mylist[left]->next;
            mylist[left]->next = mylist[right];
            mylist[right]->next = temp;
            left++;
            right--;
        }
        if (right > 0 && right < mylist.size()) mylist[right]->next = NULL;
        head = head ? mylist[0] : NULL;
    }
};