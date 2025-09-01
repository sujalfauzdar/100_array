#include<iostream>
#include<vector>

using namespace std;

    vector<int> subarraySum(vector<int> &nums,int target){
        int left = 0;
        int windowSum = 0;
        for(int right = 0 ; right < nums.size() ; right++){
            windowSum += nums[right];

            while(windowSum > target && left <= right){
                windowSum -= nums[left];
                left++;
            }
            if(windowSum == target)return {left + 1, right + 1};

        }
        return {-1};
    }

int main(){
    vector<int> nums = { 1,3,4,5,7,6};
    int target = 12;
    vector<int> result = subarraySum(nums,target);
    for(int i : result) cout<<i << " ";

    return 0;
}