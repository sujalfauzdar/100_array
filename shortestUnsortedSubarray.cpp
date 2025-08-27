#include<iostream>
#include<vector>
#include<climits>

using namespace std;

    int findUnsortedSubarray(vector<int> &nums ){
        int n = nums.size();

        int minLimit = INT_MIN;
        int maxLimit = INT_MAX;
        int rightIndex = -1;
        int leftIndex = -1;

        for(int i = 0 ; i  < n ;i++){
            if(nums[i] < minLimit) rightIndex = i;
            else minLimit = nums[i];

            if(nums[n-1-i] > maxLimit) leftIndex = n-1-i;
            else maxLimit = nums[n-1-i];
        }
        return (leftIndex == -1) ? 0 : rightIndex - leftIndex + 1;
    }

int main(){
    int n;
    cout<<"Enter the Size of Array : "<<endl;
    cin>> n;

    vector<int> nums (n,0);
    for(int i = 0 ; i < n;i++)
        cin>>nums[i];
    cout<<findUnsortedSubarray(nums);

    return 0;

}