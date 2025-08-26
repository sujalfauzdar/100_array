#include<iostream>
#include<vector>

using namespace std;
    void pushZerosEnd(vector<int> & nums){
        int j  = 0;
        for(int i = 0 ;i < nums.size() ; i++){
            if(nums[i] != 0)
                swap(nums[i],nums[j++]);
        }
    }
int main(){
    vector<int> nums ={1, 2, 0, 4, 3, 0, 5, 0};
    pushZerosEnd(nums);

    for(int num : nums)
        cout<<num<<" ";
    return 0;
}