#include<bits/stdc++.h>
using namespace std;
void printArray( int arr[], int Size )
{
    for( int i = 0; i < Size; i++ )
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
int main()
{
    int Size;
    cin >> Size;
    int arr[Size];
    for( int i = 0; i < Size; i++ )
    {
        cin >> arr[i];
    }

    //Applying Bubble Short
    for( int i = 1; i < Size; i++ )
    {
        cout << "iteration "<< i << endl;
        int flag = 0;
        for( int j = 0; j < Size-i; j++ )
        {
            if( arr[j] > arr[j+1] )
            {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                flag = 1;
            }
            printArray( arr, Size);
        }
            cout << endl;
        if( flag == 0 ) break;
    }
    printArray( arr, Size );
    return 0;
}
