#include<iostream>
#include<vector>
#include<climits>

using namespace std;

    vector<int> findSum(vector<int> & nums, int k ){
        int n = nums.size();
        int m = n - k + 1;

        vector<int> sums(m),left(m,0),right(m,0);
        int windowSum = 0;

        for(int i = 0 ; i < n ;i++){
            windowSum += nums[i];
            if(i >= k) windowSum -= nums[i - k];
            if(i >= k -1) sums[i - k + 1] = windowSum;
        }

        int bestIndex = 0;
        for(int i =1 ; i < m ;i++){
            if(sums[bestIndex] < sums[i]) bestIndex = i ;
            left[i] = bestIndex;
        }
        bestIndex = m-1;
        for(int i =m-2 ; i >=0 ; i--){
            if(sums[bestIndex] <= sums[i]) bestIndex = i;
            right[i] = bestIndex;
        }
        vector<int> ans(3,-1);
        int maxSum = INT_MIN;

        for(int mid =k ; mid < m - k ;mid++){
            int leftIndex = left[mid - k];
            int rightIndex = right[mid + k];
            int sum = sums[leftIndex] + sums[rightIndex] + sums[mid];

            if(sum > maxSum) {
                ans = { leftIndex,mid,rightIndex};
                maxSum = sum;
            }
        }
        return ans;
    }
int main(){
    int n ;
    cout<<"Enter the Size of Array (Must be of 3 * k): ";
    cin>>n;
    int k;
    cout<<"Enter value of k : ";
    cin>>k;
    vector<int> nums(n);
    for(int i = 0 ; i < n; i++)
        cin>>nums[i];
    vector<int> result = findSum(nums,k);

    for(int i : result)
        cout<<i << " ";

    return 0;
}