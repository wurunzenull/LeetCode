#include "common.h"
class Solution {
   public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        int n = firstList.size(), m = secondList.size();
        int i = 0, j = 0;
        vector<vector<int>> ans;
        while (i < n && j < m) {
            vector<int> cur_i = firstList.at(i), cur_j = secondList.at(j);
            if (cur_i[0] <= cur_j[0] && cur_j[0] <= cur_i[1]) {
                ans.push_back({cur_j[0], min(cur_j[1], cur_i[1])});
                if (cur_j[1] <= cur_i[1]) {
                    j++;
                    firstList[i][0] = cur_j[1];
                } else {
                    i++;
                    secondList[j][0] = cur_i[1];
                }
            } else if (cur_j[0] <= cur_i[0] && cur_i[0] <= cur_j[1]) {
                ans.push_back({cur_i[0], min(cur_j[1], cur_i[1])});
                if (cur_j[1] <= cur_i[1]) {
                    j++;
                    firstList[i][0] = cur_j[1];
                } else {
                    i++;
                    secondList[j][0] = cur_i[1];
                }
            } else if (cur_i[1] <= cur_j[0]) {
                i++;
            } else if (cur_j[1] <= cur_i[0]) {
                j++;
            } else {
                assert(0);
            }
        }
        return ans;
    }
};

int main() {
    Solution mySolution;
    vector<vector<int>> firstList, secondList;
    while (true) {
        firstList = readMatrix();
        secondList = readMatrix();
        vector<vector<int>> ans;
        ans = mySolution.intervalIntersection(firstList, secondList);
        printMatrix(ans);
    }
}