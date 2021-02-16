#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    void findCombination(vector<vector<int>>& combinations, vector<int>& combination, vector<int>& candidates,
                         int target, int start) {
        if (target == 0) {
            combinations.push_back(combination);
            return;
        }
        for (int i = start; i < candidates.size(); i++) {
            int candidate = candidates[i];
            if (target < candidate) break;
            if (i > start && candidate == candidates[i - 1]) continue;
            combination.push_back(candidate);
            findCombination(combinations, combination, candidates, target - candidate, i + 1);
            combination.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> combinations;
        vector<int> combination;
        sort(candidates.begin(), candidates.end());
        findCombination(combinations, combination, candidates, target, 0);
        return combinations;
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
    vector<int> candidates = readArrays();
    int target;
    cin >> target;
    Solution mySolution;
    vector<vector<int>> combinations = mySolution.combinationSum2(candidates, target);
    for (auto combination : combinations) {
        for (auto condidate : combination) {
            cout << condidate << " ";
        }
        cout << endl;
    }
    return 0;
}