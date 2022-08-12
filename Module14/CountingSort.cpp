#include<bits/stdc++.h>
using namespace std;
// Array Print Here
void printArray( int arr[], int n )
{
    for( int i = 0; i < n; i++ )
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for( int i = 0; i < n; i++ )
    {
        cin >> arr[i];
    }
    cout << "Before Sort: " << endl;
    printArray( arr, n );

    //Step 1: Findind Max Value
    int maxVal = INT_MIN;
    for( int i = 0; i < n; i++ )
    {
        if( arr[i] > maxVal ) maxVal = arr[i];
    }
    cout << endl;
    cout << "Maximum Number : " << maxVal << endl;

    //Step 2 : Initialization Of 'Count' Array
    int counterArr[maxVal+1];

    for( int i = 0; i < maxVal; i++ )
    {
        counterArr[i] = 0;
    }
    //Step 3: Frequency Calculation
    for( int i = 0; i < n; i++ )
    {
        counterArr[ arr[i] ]++;
    }
    // Step 4 : Cumulative Sum Calculation
    for( int i = 1; i <= maxVal; i++ )
    {
        counterArr[i] += counterArr[i-1];
    }

    //Step 5 Final Array ---> Backward Traversal of Basic Array
    int finalArr[n];
    for( int i = n-1; i >= 0; i-- )
    {
        counterArr[arr[i]]--;
        int k = counterArr[arr[i]];
        finalArr[k] = arr[i];
    }
    cout << "After Sort: " << endl;
    printArray( finalArr, n );
    return 0;
}
