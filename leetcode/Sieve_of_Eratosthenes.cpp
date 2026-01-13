// Given an integer n, return the number of prime numbers that are strictly less than n.

#include<iostream>
#include<vector>

using namespace std;

int countPrimes(int n){
    vector<int> arr(n, 0);

    arr[0] = arr[1] = 1;

    int cnt = 0;

    for(int i = 2; i < n; i++){
        if(arr[i] == 0){
            cnt++;
            for(int j = i * 2; j < n; j = j + i){
                arr[j] = 1;
            }
        }
    }
    return cnt;
}

int main(){

    int n;
    cin >> n;

    int ans = countPrimes(n);

    cout << ans;

}