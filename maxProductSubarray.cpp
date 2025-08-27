#include<iostream>
#include<vector>

using namespace std;
    int maxProduct(vector<int> & nums){
        int currMax = nums[0];
        int currMin = nums[0];
        int maxProd = nums[0];

        for(int i = 1; i < nums.size() ; i++){
            if(nums[i] < 0)
                swap(currMax,currMin);
            currMax = max(nums[i],currMax * nums[i]);
            currMin = min(nums[i],currMin * nums[i]);

            maxProd = max(maxProd,currMax);
        }
        return maxProd;
    }
int main(){
    int n;
    cout<<"Enter the Size of Array : "<<endl;
    cin>> n;
    vector<int> nums(n,0);

    for(int i =0 ; i < n ;i++)
        cin>>nums[i];
    cout<<endl;
    cout<<maxProduct(nums);
    return 0;
}