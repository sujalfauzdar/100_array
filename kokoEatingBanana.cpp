#include<iostream>
#include<vector>
#include<algorithm>


using namespace std;

    bool canEatInTime(vector<int> &piles,int h,int speed){
        int totalHrs = 0;
        for(int i : piles){
            totalHrs += (i + speed -1 )/speed;

        }
        return totalHrs <= h;
    }

    int minEatingSpeed(vector<int> &piles,int h){
        int minSpeed = 1;
        int maxSpeed = *max_element(piles.begin(),piles.end());
        int minPossibleSpeed = maxSpeed;

        while(minSpeed <= maxSpeed){
            int newSpeed = minSpeed + (maxSpeed - minSpeed)/2;

            if(canEatInTime(piles,h,newSpeed)){
                minPossibleSpeed = newSpeed;
                maxSpeed = newSpeed - 1;
            }
            else
                minSpeed = newSpeed + 1;
        }
        return minPossibleSpeed;
    }

int main(){
    int n;
    cout<<"Enter number of piles : "<<endl;
    cin>> n;
    vector<int> piles(n);
    cout<<"Enter banana in Each pile : "<<endl;

    for(int i =0; i< n; i++)
        cin>>piles[i];
    
    int h;
    cout<<"Enter hours The guards have gone and will come back in i.e > piles.size() : "<<endl;
    cin>> h;
    cout<<"Koko can eat all Bananas in time with ";
    cout<<minEatingSpeed(piles,h)<<" speed";

    return 0;
}