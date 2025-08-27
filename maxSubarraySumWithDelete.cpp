#include<iostream>
#include<vector>
#include<climits>

using namespace std;

    int maximumSum(vector<int> & arr){
        int n = arr.size();

        if( n== 1)
            return arr[0];
        int noDelete = arr[0];
        int oneDelete = 0;
        int maxSum = INT_MIN;

        for(int i = 1; i < n ; i++){
            oneDelete = max(arr[i], max(oneDelete + arr[i] , noDelete));
            noDelete = max(arr[i], arr[i] + noDelete);

            maxSum = max(maxSum ,max(oneDelete, noDelete));
        }
        return maxSum;
    }
int main(){
    int n;
    cout<<"Enter the Size of Array : "<<endl;
    cin>> n;

    vector<int> nums (n,0);
    for(int i = 0 ; i < n;i++)
        cin>>nums[i];
    cout<<maximumSum(nums);

    return 0;

}