#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int searchLastGreater(vector<pair<int, int> >& works, int worker) {
        int left = 0, right = works.size() - 1;
        int ans = -1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (works[mid].first <= worker) {
                ans = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return ans;
    }
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        vector<pair<int, int> > works;
        int n = difficulty.size(), m = worker.size();
        for (int i = 0; i < n; i++) {
            works.push_back({difficulty[i], profit[i]});
        }
        auto cmp = [](const pair<int, int>& a, const pair<int, int>& b) {
            if (a.first != b.first) return a.first < b.first;
            return a.second > b.second;
        };
        sort(works.begin(), works.end(), cmp);
        vector<int> maxProfit(n, works[0].second);
        for (int i = 1; i < n; i++) {
            maxProfit[i] = max(maxProfit[i - 1], works[i].second);
        }

        int res = 0;
        for (int i = 0; i < m; i++) {
            int pos = searchLastGreater(works, worker[i]);
            if (pos == -1) continue;
            res += maxProfit[pos];
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
    vector<int> difficulty, profit, worker;
    Solution mySolution;
    while (true) {
        difficulty = readArrays();
        profit = readArrays();
        worker = readArrays();
        cout << mySolution.maxProfitAssignment(difficulty, profit, worker) << endl;
    }
    return 0;
}