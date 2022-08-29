#include<bits/stdc++.h>
#include"MYSTACK.h"

using namespace std;
/* 
        5
        1 2 3 4 5
        7
        1 6 43 1 2 0 5
        10
        6 5 5 5 4 7 1 2 1 2
 */
int main(){
    int n;
    cin >> n;
    int arr[n];
    for( int i = 0; i < n; i++ ){
        cin >> arr[i];
    }

    Stack<int> st;
    Stack<int> minStack;

    int min = INT_MAX;
    for( int i = 0; i < n; i++ ){
        if( arr[i] <= min ){
            minStack.push(arr[i]);
            min = arr[i];
        }
        st.push(arr[i]);
    }

    while( !st.empty()){
        // if Top Of minStack and st is equal
        if( minStack.Top() != st.Top()){
            st.pop();
            cout << minStack.Top() << " ";
        }
        //Else 
        else{
            cout << minStack.Top() << " ";
            minStack.pop();
            st.pop();
        }
    }
    cout << endl << endl;
    return 0;
}