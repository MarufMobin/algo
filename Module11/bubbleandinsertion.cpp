#include<bits/stdc++.h>
using namespace std;
void printArray( int arr[], int n ){
    for( int i = 0; i < n; i++ ){
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main(){
    int n;
    cin >> n;
    int arr[n];
    for( int i = 0; i < n; i++ ){
        cin >> arr[i];
    }
    // Bubble Sorting here
    for( int i = 1; i < n; i++ ){
        int flag = 0;
        for( int j = 0; j < n; j++ ){
            if( arr[j] > arr[j-1] ){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                flag = 1;
            }
        }
        if( flag == 0 ) break;
    }
    printArray(arr, n);
    return 0;
}
