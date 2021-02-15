#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int res, diff=INT32_MAX;
        if(nums.size()<3) return res;
        for(int i = 0; i<nums.size();i++){
            for(int j=i+1,k=nums.size()-1;j < k;){
                int sum = nums[i]+nums[j]+nums[k];
                if(abs(sum-target)<diff){
                   res=sum;
                   diff=abs(sum - target);
                }
                if(sum>target){
                    k--;
                }else {
                    j++;
                }
            }
        }
        return res;
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
    vector<int> nums = readArrays();
    int target;
    cin >> target;
    Solution mySolution;
    cout << mySolution.threeSumClosest(nums,target);
    return 0;
}