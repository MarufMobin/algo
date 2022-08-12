#include<bits/stdc++.h>
using namespace std;
void printArray( int arr[], int n )
{
    for( int i = 0; i < n; i++ ){
        cout << arr[i] << " ";
    }
    cout << endl;
}
int main(){
    int n;
    cin >> n;
    int arr[n];
    for( int i = 0; i < n; i++ )
    {
        cin >> arr[i];
    }
    printArray( arr, n );

    //Selection Sorting algorithm start here
    for( int i = 1; i < n; i++ ){
        int key = arr[i];
        int j = i-1;
        while( arr[j] > key && j >= 0 ){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
    printArray( arr, n );
    return 0;
}
