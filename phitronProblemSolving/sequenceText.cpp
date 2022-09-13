#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    char st[n];
    cin >> st;
    int plus = 0, minus = 0;
    int i = 0;
    stack<int>stk;
    while (i < n)
    {
        if( st[i] == '+' ) {
            stk.push(minus);
            minus = 0;
            plus++;
        }
        if( st[i] == '-' ){
            stk.push(plus);
            plus = 0;
            minus++;
        }
        i++;
    }
    int ans = 0;

    while( !stk.empty() ){
        cout << stk.top() << endl;
        stk.pop();
        // int topVal = stk.top();
        // stk.pop();
        // ans = max( topVal, stk.top());
    }
    // cout <<  ans << endl;
    return 0;
}