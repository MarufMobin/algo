#include<bits/stdc++.h>
using namespace std;

void printArray( int arr[], int n )
{
    for( int i = 0; i < n; i++ ){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
void insertion( int arr[], int n, int pos, int val )
{
    for( int i = n-1; i >= pos; i-- ){
        arr[i+1] = arr[i];
    }
    arr[pos] = val;
}
int main(){
    int arr[50];

    int n;
    cin>>n;
    for( int i = 0; i < n; i++ )
    {
        cin>>arr[i];
    }
    //Print the Traversal Array
    cout<<"Given Output : ";
    printArray( arr, n );

    //Insertion Array Value
    int pos, val;
    cout<<"Give me a Position : ";
    cin>>pos;
    cout<<"Give me a Value : ";
    cin>>val;

    if( pos < 0 || pos > n ){
        cout<<"Invalid Position ";
    }else{
        // Size-1 (4) ----> pos(2)
        insertion( arr, n, pos, val );
    }
    cout<<"Given Output : ";
    printArray( arr, n+1 );

    return 0;
}
