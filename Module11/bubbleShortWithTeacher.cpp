#include<bits/stdc++.h>
using namespace std;
void printArray( int arr[], int Size ){
    for( int i = 0; i < Size; i++ ){
        cout << arr[i] << " ";
    }
    cout << endl;
}
int main(){
    int Size;
    cin >> Size;
    int arr[Size];

    for( int i = 0; i < Size; i++ ){
        cin >> arr[i];
    }
    cout << "Before Short : ";
    printArray( arr, Size );

    //Bubble Short Implementation
    for( int i = 1; i < Size; i++ ){
        for( int j = 0; j < Size-1; j++ ){
            if( arr[j] > arr[j+1] ){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    cout << "After Short : ";
    printArray( arr, Size );
    return 0;
}
