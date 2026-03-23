#include<iostream>
#include<vector>

using namespace std;

bool DBMDarray(vector<int> &v, int n, int s, int x){
    int sum = 0;
    for(int i = 0; i < n; i++){
        sum += v[i]; 
    }
    
    if((s - sum) <= 0 && (s-sum) % x == 0) return true; 
    else return false;

    
}

int main(){
    int t;
    cin >> t;
    for(int i = 0; i < t; i++){
        
        int n,s,x;
        vector<int> v;
        cin >> n;
        cin >> s;
        cin >> x;
        for(int j = 0; j < n; j++){
            int a;
            cin >> a;
            v.push_back(a);
        }

        bool ans = DBMDarray(v, 3,3,5);
        if(ans){
            cout << "YES";
        }
        else{ cout << "NO"; }

        


    }
   
}

// int t;
//     cin >> t;
//     while (t--) {
//         int n, s, x;
//         cin >> n >> s >> x;

//         int sum = 0;
//         for (int i = 0; i < n; i++) {
//             int a;
//             cin >> a;
//             sum += a;
//         }

//         if (sum <= s && (s - sum) % x == 0) {
//             cout << "YES\n";
//         } else {
//             cout << "NO\n";
//         }
//     }
//     return 0;