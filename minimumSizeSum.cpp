//return the minimum size subarray with sum >= target
#include<iostream>
#include<vector>
#include<climits>

using namespace std;

int n;

    int minimumSizeSubarray(vector<int> &nums ,int target){
        int minLen = INT_MAX;
        int left = 0;
        long long windowSum = 0;

        for(int right = 0 ; right < n; right++){
            windowSum += nums[right];
            while(windowSum >= target){
                minLen = min(minLen,right - left + 1);
                windowSum -= nums[left];
                left++;
            }
        }
        return minLen == INT_MAX ? 0 : minLen;
    }

int main(){
    cout<<"Enter the Size of array : ";
    cin>> n;
    vector<int> nums(n);
    for(int i = 0 ; i < n;i++)
        cin>>nums[i];
    int target;
    cout<<"Enter the target sum"<<endl;
    cin>>target;
    cout<<endl;

    cout<<minimumSizeSubarray(nums,target);

    return 0;
}