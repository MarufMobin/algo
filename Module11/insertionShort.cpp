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
    //Before Shorting
    cout << "Before Sorting : ";
    printArray( arr, n );
    cout << endl;

    //Insertion Sort Algorithm
    for( int i = 1; i < n; i++ ){
        cout << i << " This is Iteration ";
        int key = arr[i];
        int j = i-1;
        while( arr[j] > key && j >= 0 ){
            arr[j+1] = arr[j];
            cout << arr[j+1]  << endl;
            j--;
        }
        arr[j+1] = key;
    }

    cout << "After Sorting : ";
    printArray( arr, n );
    cout << endl;
    return 0;
}

