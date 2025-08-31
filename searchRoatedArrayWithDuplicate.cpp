// search in sorted roated array with duplicate return bool in O(log n)

#include<iostream>
#include<vector>

using namespace std;

    bool search(vector<int> &nums ,int target){
        int left = 0;
        int right = nums.size() - 1;

        while(left <= right){
            int mid = left + (right - left)/2;

            if(nums[mid] == target)
                return true;
            if(nums[left] == nums[mid] && nums[mid] == nums[right]){
                left++;
                right--;
            }
            else if( nums[left] <= nums[mid]){
                if(nums[left] <= target && nums[mid] > target) right = mid -1 ;
                else left = mid + 1;

            }
            else {
                if(nums[right] >= target && nums[mid] < target) left = mid + 1;
                else right = mid - 1;
            }

        }
        return false;
    }
int main(){
    vector<int> nums = {1,1,1,2,3,1};
    int target = 3;
    cout<<boolalpha;
    cout<<search(nums,target);

    return 0;

}