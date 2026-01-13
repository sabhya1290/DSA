#include<iostream>
#include<vector>
#include<string>

using namespace std;

int getLength(char a[]){
    int count = 0; 
    for(int i = 0; a[i] != '\0'; i++ ){
        count++;
    }
    return count;
}

char toLower(char a){
    if(a >= 'a' && a <= 'z'){
        return a;
    }
    else{
        return a - 'A' + 'a';
    }
}

void reverseStr(char a[], int l){
    
    for(int i = 0; i < l/2 ;i++ ){
        swap(a[i] , a[l-i-1]);
    }
    
}

bool palindrome(char a[], int l){

    int s = 0;
    int e = l - 1;
    while(s < e){
        cout << s << e <<endl;


        if(a[s] < 'A') s++;

        else if(a[e] < 'A') e--;

        else if (toLower(a[s]) != toLower(a[e])){
            return false;
        }
        else{
        s++;
        e--;
        }
    }
    return true;

}

void reverseBelowWord(vector<char> &s, int st , int e ){
    while(st < e){
        swap(s[st++] , s[e--]);
    }
}

void reverseWord(vector<char> &s){

    int start = 0;
    int c = 0;
    int l = s.size();

    for(int i = 0; i < l; i++){
        if(s[i] == ' '){
            reverseBelowWord(s, start, c - 1);
            start = c + 1;
        }
        c++;
    }
    reverseBelowWord(s, start, c-1);

    // printing
    for(auto it: s){
        cout << it  ;
    }
    cout << endl;


}

void printStr(vector<char> s){
        for(auto it: s){
        cout << it  ;
    }
    cout << endl;

}

void reverseArrNotWord(vector<char> &s){
    
    // reverseStr(s, s.size());
    
    for(int i = 0; i < s.size()/2 ;i++ ){
        swap(s[i] , s[s.size()-i-1]);
    }
    
    reverseWord(s);

}

char maxOccChar(string s){
    
    int arr[26] = {0};

    for(int i = 0 ; i < s.size(); i++){
        int n = 0;
        char ch = s[i];
        if(ch >= 'a' && ch <= 'z'){
            n = ch - 'a';
        }
        else{
            n = ch - 'A';        
        }
        arr[n]++;
    }
    

    int maxi = -1;
    int ans;
    for(int i = 0; i < 26; i++){
        if(maxi < arr[i]){
            ans = i;
            maxi = arr[i];
        }
    }
    return ans + 'a';
}

void removeSpace(string &s) {
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == ' ') {
            s.replace(i, 1, "@40");
            i += 2;  
        }
    }
}

void removeOccurrences(string &s, string part) {
// bad me
    cout << part.length() << endl;
    int k = 0;
    while(k < s.length()){
        int i = 0;
        int j = 0;
        int c = 1;
        while(i < s.length() && j < part.length()){
            if(s[i] == part[j]){
                c++;
                i++;
                j++;
                cout << "c-" << c << " j-" << j << " " << "i-" << i <<' ';
            }
            else if (j == part.length()-1){
                // cout << c <<" ";
                break;
            }
            else{
                // c = 0;
                i++;
                j = 0;
            }

            if(c == part.length()){
                cout << i << "-remove" << endl;
                s.erase(i, part.length());
            }
            
        }
        k++;
    }

    // for(int i = 0; i < s.length() ; i++){
    //     int c = 0;
        
    //     for(int j = 0; j < part.length(); j++){
    //         if(s[i] != s[j]){
    //             break;
    //         }
    //         else{
    //             c++;
    //             cout << c << endl;
    //         }
    //         cout << c << endl;
    //     }
    //     if(c == part.length()){
    //         s.erase(i, part.length());
    //     }
    // }
}

bool checkEqual(int arr1[], int arr2[]){
    for(int i = 0; i < 26; i++){
        if(arr1[i] != arr2[i]){
            return false;
        }
    }
    return true;
}

bool checkInclusion(string s1, string s2){
    int count1[26] = {0};

    int windowSize = s1.length();

    for(int i = 0; i < windowSize; i++){
        int index = s1[i] - 'a';
        count1[index]++; 
    }

    int i = 0;
    int count2[26] = {0};

    while(i < windowSize && i < s2.length()){
        int index = s2[i] - 'a';
        count2[index]++; 
        i++;
    }

    if (checkEqual(count1, count2)){
        return true;
    }

    while(i < s2.length()){
        char newChar = s2[i] - 'a';
        count2[newChar]++;

        char oldChar = s2[i - windowSize] - 'a';
        count2[oldChar]--;

        if (checkEqual(count1, count2)){
            return true;
        }
        
        i++;
    }

    return false;

}

string removeDuplicates(string s) {
    
    
    // int i = 0, l = s.length() - 1 ;
    // while(i < l){
    //     if(s[i] == s[i + 1]){
    //         s.erase(i , 2);
    //         i--;
    //         l -= 2;
    //     }
    //     else{i++;}
    //     if(i<0){
    //         i = 0;
    //     }
    // }
    // return s;
}

int compress(vector<char>& chars) {
        if(chars.size() == 1) return 1;

        char key = chars[0];
        int value = 1;
        vector<char> ans;
        for(int i = 0; i < chars.size(); i++){
            int j = i + 1;
            while(j < chars.size() && chars[i] == chars[j]){
                value++;
                j++;
                i = j - 1;
            }
            string v = to_string(value);
            ans.push_back(chars[i]);
            if(value == 1){
                continue;
            }
            ans.insert(ans.end(),v.begin(), v.end() );
            value = 1;     
        }
        chars = ans;
        return ans.size();
}

int main(){

    // char a[] = "0P";
    // int length = getLength(a);
    // reverseStr(a, length);
    // cout << a << endl;
    // cout << palindrome(a, length)<< endl;

    // vector<char> s = {'t','h','e',' ','s','k','y',' ','i','s',' ','b','l','u','e'};
    // // reverseWord(s);
    // reverseArrNotWord(s);
    // printStr(s);

    // string s = " hello hii my name is ___";
    // // cout << maxOccChar(s);

    // removeSpace(s);
    // cout << s;

    // string  s = "axxxxyyyyb", part = "xy";
    // removeOccurrences(s, part);
    // cout << s;

    // string s1 = "ab", s2 = "efifbafl";
    // cout << checkInclusion(s1, s2); 

    vector<char> c = {'a','b','b','b','b','b','b','b','b','b','b','b','b'};
    int ans = compress(c);
    cout << ans;




}