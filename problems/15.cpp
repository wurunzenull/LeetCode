#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        if(nums.size()<3) return {};
        sort(nums.begin(),nums.end());
        vector<vector<int>> res;
        for(int i=0;i<nums.size()-2;i++){
            if(nums[i]>0)
                break;
            if(i>0 && nums[i]==nums[i-1])
                continue;
            int j=i+1;
            int k = nums.size()-1;
            for(;j<k;){
                int addRes=nums[i]+nums[j]+nums[k];
                if(addRes==0){
                    res.push_back({nums[i],nums[j],nums[k]});
                    j++;
                    k--;
                    while(j<k && nums[j]==nums[j-1])
                        j++;
                    while(j<k && nums[k]==nums[k+1])
                        k--;
                }
                else if(addRes>0){
                    k--;   
                }
                else{
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
    Solution mySolution;
    vector<vector<int>> result=mySolution.threeSum(nums);
    for(auto tuple:result){
        for(auto ele:tuple){
            cout<<ele<<" ";
        }
        cout<<endl;
    }
    return 0;
}