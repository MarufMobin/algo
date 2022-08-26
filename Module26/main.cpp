#include<bits/stdc++.h>
#include"MYQUEUETEMP.h"
using namespace std;

// typedef pair< int , int > mytype;
typedef pair< char , int > mytype;

int main(){
    // Queue<int> q;
    Queue<mytype> q;
    int n;
    cin >> n;
    for( int i = 0; i < n; i++ ){
        char c1;
        int c2;
        cin >> c1 >> c2;
        q.push(make_pair(c1, c2));
        // int chk;
        // cin >> chk;
        // q.push(chk);
    }
    cout << endl << endl;
    while( !q.empty() ){
        mytype chk;
        chk  = q.pop();
        cout << chk.first  << " | " << chk.second << endl;
    }

    // if( !q.empty() ){
    //     cout << q.Front().first << endl;
    //     cout << q.Front().second << endl;
    // }
    // if( !q.empty() ){
    //     cout << q.Back().first << endl;
    //     cout << q.Back().second << endl;
    // }
    return 0;
}