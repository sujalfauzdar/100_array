#include<iostream>
#include<vector>
#include<iomanip>

using namespace std;

    int firstMissingPositive(vector<int>& nums) {
       int n = nums.size();
       
       for(int i =0 ;i < n ;i++){
        while(nums[i] > 0 && nums[i] <= n && nums[nums[i] - 1] != nums[i] )
            swap(nums[nums[i] - 1],nums[i]);

       }
       for(int i =0 ; i < n ;i++){
        if(nums[i] != i + 1)
            return i + 1;

       }
       return n + 1;
    }
int main(){
    int n ;
    cout<<"Enter the Size of Vector : "<<endl;
    cin>>n;
    vector<int> nums(n);

    for(int i = 0 ; i < n ;i++)
        cin>> nums[i];

    cout << setfill('-') << setw(80) << "-" << endl;   
    cout<<firstMissingPositive(nums)<<endl;

    return 0;
}