#include<bits/stdc++.h>
using namespace std;
PrintArray( int n, int arr[] ){
    for( int i = 0; i < n; i++ ){
        cout<<arr[i]<<" ";
    }
}
int main(){
    int n;
    cin>>n;
    int arr[50];
    for( int i = 0; i < n; i++ ){
        cin>>arr[i];
    }
    PrintArray( n , arr );

    int pos;
    cout<<"Give me a Position No which one Delete : ";
    cin>>pos;

    if( pos < 0 || pos > n - 1 ) //Insertion --> size , Deletion --> size - 1
    {
        cout<<"Invalid Index"<<endl;
    }
    else{
        if( pos == n-1 ) n--; //Only Last Position that Condition Apply
        else{
            //pos+1 ---> size - 1
            // Start and any Position then that Condition Apply
            for( int i = pos+1; i < n; i++ ){
                arr[i-1] = arr[i];
            }
            n--;
        }
    }
    cout<<endl;
    cout<<"Array After the Deletion : ";
    PrintArray( n, arr);
    return 0;
}
