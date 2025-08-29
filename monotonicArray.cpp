#include<iostream>
#include<vector>

using namespace std;
int n;

    bool isMonotonic(vector<int> & nums){
        if(n == 1)
            return true;
        bool increasing = true;
        bool decreasing = true;

        for(int i =0 ;i < n-1 ;i++){
            if(nums[i] > nums[i+1]) increasing = false;
            if(nums[i] < nums[i+1] ) decreasing = false;

        }
        return increasing || decreasing;
    }

int main(){
    cout<<"Enter the Size of Array : ";
    cin>>n;
    vector<int> nums(n);
    for(int i =0 ;i < n;i++)
        cin>>nums[i];
    cout<<boolalpha;
    cout<<isMonotonic(nums);

    return 0;
}