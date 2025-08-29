#include<iostream>
#include<vector>

using namespace std;
int n;

    void sortColor(vector<int> &nums){
        int start = 0 ,mid = 0,end = n-1;
        while(mid <= end){
            if(nums[mid] == 0){
                swap(nums[mid],nums[start]);
                start++;
                mid++;
            }
            else if(nums[mid] == 1) mid++;
            else{
                swap(nums[mid],nums[end]);
                end--;
            }
        }
    }
int main(){

    cout<<"Enter the Size of array : ";
    cin>>n;
    vector<int> nums(n);
    for(int i =0 ;i < n ;i++)
        cin>>nums[i];
    sortColor(nums);

    for(int i :nums )
        cout<<i << " ";

    return 0;
}