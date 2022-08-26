
#include<bits/stdc++.h>
#include"MYQUEUE.h"
using namespace std;

int main(){
    Queue q;
    int n;
    cin >> n;
    for( int i = 0; i < n; i++ ){
        int chk;
        cin >> chk;
        q.push(chk);
    }
    cout << endl << endl;
    // while( !q.empty() ){
    //     cout << q.pop() << " ";
    // }
    if( !q.empty() ){
        cout << q.Front() << endl;
    }
    if( !q.empty() ){
        cout << q.Back() << endl;
    }
    return 0;
}