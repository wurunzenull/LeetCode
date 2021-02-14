#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <iomanip>
using namespace std;

class Solution
{
public:
    /*
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> nums;
        int i = 0,j = 0;
        for(;i<nums1.size()&&j<nums2.size();){
            if(nums1[i]<nums2[j]) {
                nums.push_back(nums1[i++]);
            }
            else {
                nums.push_back(nums2[j++]);
            }
        }
        for(;i<nums1.size();i++) {
            nums.push_back(nums1[i]);
        }
        for(;j<nums2.size();j++) {
            nums.push_back(nums2[j]);
        }
        if(nums.size()%2) {
            return nums[(nums.size()-1)/2];   
        }
        return (nums[nums.size()/2-1]+nums[nums.size()/2])/2.0;
    }
    */
    int getKthSortedArrays(const vector<int> &nums1, const vector<int> &nums2, int k)
    {
        int m = nums1.size(), n = nums2.size();
        int index1 = 0, index2 = 0;
        while (true)
        {
            if (index1 == m)
            {
                return nums2[index2 + k - 1];
            }
            if (index2 == n)
            {
                return nums1[index1 + k - 1];
            }
            if (k == 1)
            {
                return min(nums1[index1], nums2[index2]);
            }
            int newIndex1 = min(index1 + k / 2 - 1, m - 1);
            int newIndex2 = min(index2 + k / 2 - 1, n - 1);
            if (nums1[newIndex1] <= nums2[newIndex2])
            {
                k -= newIndex1 - index1 + 1;
                index1 = newIndex1 + 1;
            }
            else
            {
                k -= newIndex2 - index2 + 1;
                index2 = newIndex2 + 1;
            }
        }
    }

    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        int totalSize = nums1.size() + nums2.size();
        if (totalSize % 2)
        {
            return getKthSortedArrays(nums1, nums2, (totalSize + 1) / 2);
        }
        return (getKthSortedArrays(nums1, nums2, totalSize / 2) \
        + getKthSortedArrays(nums1, nums2, totalSize / 2 + 1)) / 2.0;
    }
};

vector<int> readArrays()
{
    vector<int> nums;
    string input;
    getline(cin, input);
    istringstream in(input);
    int num;
    while (in >> num)
    {
        nums.push_back(num);
    }
    in.clear();
    return nums;
}

int main()
{
    vector<int> nums1 = readArrays();
    vector<int> nums2 = readArrays();
    // for(auto num:nums1){
    //     cout<<num<<" ";
    // }
    // for(auto num:nums2){
    //     cout<<num<<" ";
    // }
    Solution mySolution;
    cout << fixed << setprecision(5) << mySolution.findMedianSortedArrays(nums1, nums2) << endl;
    return 0;
}