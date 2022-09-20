#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> PAIR;

int main(){
    /* vector<int> V( 3, -1);
    //Using Iterator 
    vector<int>:: iterator it;
    V.push_back(4);
    for( it = V.begin(); it != V.end(); it++){
        cout << *it << endl;
    } */

    // vector<int> V( 3, -1);
    // for( int i = 0; i < V.size(); i++){
    //     cout << V[i] << " ";
    // }

    // cout << endl;
    // V.push_back(4);
    // vector<int>:: iterator it;
    // for( it = V.begin(); it != V.end(); it++){
    //     cout << *it << " ";
    // }
    // cout << endl;

    //  'auto' Register in Range Based traversal 
    // vector<int> V( 3, -1);
    // for( auto element: V ){
    //     cout << element << " ";
    // }
    // cout << endl;
    // // Auto Register in place of iterator 
    // for( auto it = V.begin(); it != V.end(); it++ ){
    //     cout << *it << endl;
    // }


    // priority_queue<int, vector<int>> PQ; Max ar Khatre Use hoi 
    // priority_queue<int, vector<int>, greater<int>> PQ; // Min ar Khatre greater use hoi 
    priority_queue<PAIR, vector<PAIR>, greater<PAIR>> PQ;
    PQ.push(make_pair(1, 9));
    PQ.push(make_pair(6, 2));
    PQ.push(make_pair(4, 1));
    while( !PQ.empty() ){
        cout <<  PQ.top().first << " | " << PQ.top().second << endl;
        PQ.pop();
    }
    return 0;
}