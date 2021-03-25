#include "common.h"
class Solution {
   public:
    int numSubarraysWithSum(vector<int>& A, int S) {
        int n = A.size();
        if (!n) return 0;
        int i_lo = 0, i_hi = 0;
        int ans = 0;
        int lo_sum = 0, hi_sum = 0;
        for (int j = 0; j < n; j++) {
            lo_sum += A[j];
            while (i_lo < j && lo_sum > S) {
                lo_sum -= A[i_lo++];
            }
            hi_sum += A[j];
            while (i_hi < j && (hi_sum > S || (hi_sum == S && A[i_hi] == 0))) {
                hi_sum -= A[i_hi++];
            }
            if (lo_sum == S) {
                ans += i_hi - i_lo + 1;
            }
        }
        return ans;
    }
};
int main() {
    Solution mySolution;
    vector<int> A;
    int S;
    while (true) {
        A = readArrays();
        cin.clear();
        cin >> S;
        printArray(A);
        cout << S << endl;
        cout << mySolution.numSubarraysWithSum(A, S) << endl;
    }
}