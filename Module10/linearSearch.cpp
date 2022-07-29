#include<bits/stdc++.h>
using namespace std;
void PrintArray( int arr[], int n )
{
    for( int i = 0; i < n; i++ )
    {
        cout<<arr[i]<<" ";
    }
}
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for( int i = 0; i < n; i++ )
    {
        cin>>arr[i];
    }
//    PrintArray( arr, n );
    char c;
    cout<<"Do you want to search : ( Y / N ) ";
    cin>>c;

    while( toupper(c) == 'Y' )
    {

        int x;
        cout<<" Please enter the value you want to search : ";
        cin>>x;
        int flag = 0;
        for( int i = 0; i < n; i++ )
        {
            if( arr[i] == x )
            {
                cout<<"Index No -> "<<i <<" Position No -> " << i+1 <<endl;
                flag++;
            }
        }

        if( flag == 0 ) cout<<"Not Found"<<endl;

        cout<<"Do you want to Continue Search : ( Y / N ) ";
        cin>>c;
    }
    return 0;
}
