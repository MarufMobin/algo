#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    int arr[n];
    int prefixArr[n];
    int sum = 0;
    for( int i = 0; i < n; i++ ){
        cin >> arr[i];
        sum += arr[i];
        prefixArr[i] = sum;
    }
    for( int i = 0; i < n; i++ ){
        cout << arr[i] << " ";
    }
    cout << endl;
    for( int i = 0; i < n; i++ ){
        cout << prefixArr[i] << " ";
    }
    return 0;
}
