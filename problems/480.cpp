#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    priority_queue<int, vector<int> > bigRootPq;
    priority_queue<int, vector<int>, greater<int> > smallRootPq;
    unordered_map<int, int> hashTable;
    double get(int k) {
        if (k % 2) {
            return bigRootPq.top();
        } else {
            return (double(bigRootPq.top()) + smallRootPq.top()) / 2.0;
        }
    }
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        for (int i = 0; i < k; i++) {
            bigRootPq.push(nums[i]);
        }
        for (int i = 0; i < k / 2; i++) {
            smallRootPq.push(bigRootPq.top());
            bigRootPq.pop();
        }
        vector<double> res{get(k)};
        int n = nums.size();
        for (int i = k; i < n; i++) {
            int balance = 0;
            int left = nums[i - k];
            hashTable[left]++;
            if (!bigRootPq.empty() && bigRootPq.top() >= left) {
                balance--;
            } else {
                balance++;
            }
            int right = nums[i];
            if (bigRootPq.top() >= right) {
                bigRootPq.push(right);
                balance++;
            } else {
                smallRootPq.push(right);
                balance--;
            }
            if (balance > 0) {
                smallRootPq.push(bigRootPq.top());
                bigRootPq.pop();
            }
            if (balance < 0) {
                bigRootPq.push(smallRootPq.top());
                smallRootPq.pop();
            }
            while (!bigRootPq.empty() && hashTable[bigRootPq.top()] > 0) {
                hashTable[bigRootPq.top()]--;
                bigRootPq.pop();
            }
            while (!smallRootPq.empty() && hashTable[smallRootPq.top()] > 0) {
                hashTable[smallRootPq.top()]--;
                smallRootPq.pop();
            }

            res.push_back(get(k));
        }
        return res;
    }
};

vector<int> readArrays() {
    vector<int> nums;
    string input;
    getline(cin, input);
    istringstream in(input);
    int num;
    while (in >> num) {
        nums.push_back(num);
    }
    in.clear();
    return nums;
}

int main() {
    vector<int> nums;
    int k;
    Solution mySolution;
    while (true) {
        nums = readArrays();
        cin >> k;
        vector<double> medians = mySolution.medianSlidingWindow(nums, k);
        for (auto median : medians) {
            cout << median << " ";
        }
        cout << endl;
    }
}