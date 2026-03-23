#include<iostream>
#include<vector>
#include<string>

using namespace std;

void reverseString(string &a, int i){
    
    if(i > a.length()/ 2) return;
    swap(a[i], a[a.length() - i - 1]);
    reverseString(a, i + 1 );

}

bool checkPalindrom(string s, int len, int i){

    if(i >= len) return true; 

    if(s[i] == s[len]){
        return checkPalindrom(s, len - 1, i + 1);
    }
    return false;
}

int power(int a, int b){
    if(b == 0) return 1;
    if(b == 1) return a;
    
    if(b % 2 == 0){
        return power(a, b/2) * power(a, b/2);
    }
    else{
        return a * power(a, b/2) * power(a, b/2);
    }
}

int main(){

    // string a = "saasaas";
    // cout << a << endl;

    // for(int i = 0 ; i < a.length() / 2; i++){
    //     swap(a[i], a[a.length() - 1 - i]);
    // }
    // cout << a << endl;
    // reverseString(a, 0);
    // cout << a << endl;
    
    // bool ans = checkPalindrom(a, a.length() - 1, 0);
    // cout << ans << endl;

    // int a = 3, b = 10;
    // cout << power(a, b);

   

}


