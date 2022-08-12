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
    for( int i = 0; i < n; i++ ){
        cin >> arr[i];
    }
    // Before Shorting
    cout << "Before Sorting : ";
    printArray( arr, n );
    for( int i = 1; i < n; i++ ){
        for( int j = 0; j < n-1; j++ ){
            cout << i << " -> " << arr[j] ;
            cout << endl << endl;
            if( arr[j] > arr[j+1] ){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    //After Shorting
    cout << "After Sorting : ";
    printArray( arr, n );

    return 0;
}
