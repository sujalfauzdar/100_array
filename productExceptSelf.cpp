#include<iostream>
#include<vector>

using namespace std;
    vector<int> productExceptSelf(vector<int>& nums){
        int n = nums.size();

        int prefixProd = 1;
        int suffixProd = 1;

        vector<int> productArray(n,1);
        for(int i = 0 ;i < n ;i++){
            productArray[i] = prefixProd;
            prefixProd *= nums[i];
        }
        for(int i = n-1;i >=0;i--){
            productArray[i] *= suffixProd;
            suffixProd *= nums[i];
        }
        return productArray;
    }
int main(){
    vector<int> nums = {10, 3, 5, 6, 2};
    vector<int> ans = productExceptSelf(nums);
    for(int i : ans)
        cout<<i<<" ";
    
    return 0;
}