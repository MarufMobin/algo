#include<bits/stdc++.h>
using namespace std;
int Sort( int arr[] , int n ){
    int Max = arr[0];
    for( int i = 0; i < n; i++ ){
        if( Max < arr[i] ){
            int temp = arr[i];
            arr[i] = Max;
            Max = temp;
        }
    }
}
void PrintArray( int arr[], int n ){
    for( int i = 0; i < n; i++ ){
        cout<<arr[i]<<" ";
    }
}

int binarySearch( int arr[], int x, int lb, int ub ){
    if( lb <= ub ){
        int mid = ( lb + ub ) / 2 ;

        //x == [mid]
        if( x == arr[mid] ) return mid; // Exact Center
        //x > arr[mid]
        else if( x > arr[mid] ) binarySearch( arr, x, mid+1, ub ); // Right
        //x < arr[mid]
        else binarySearch( arr, x, lb, mid-1 ); //Left
    }
    else return  -1;
}

int main(){

    int n;
    cin>>n;
    int arr[n];
    for( int i = 0; i < n; i++ ){
        cin>>arr[i];
    }
    //Short Function are here
//    Sort( arr, n );


    int x;
    cout<<"Which Value you Want : ";
    cin>>x;

    //Binary Search Algorithm here
    int indexNumber;
    indexNumber = binarySearch( arr, x, 0, n-1 );

    if( indexNumber != -1 ){
        cout<<"Index No: "<<indexNumber<<" Position No: "<< indexNumber+1<<endl;
    }else{
        cout<<" Not Found";
    }
    return 0;
}
