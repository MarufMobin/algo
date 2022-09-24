#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int>PAIR;
int main(){
    int k;
    cin >> k;
    vector< vector< int > > allValues(k);

    //Input Tacken
    for( int i = 0; i < k; i++ ){
         int size;
         cin >> size;
         allValues[i] = vector<int>(size);
         for( int k = 0; k < size; k++ ){
            cin >> allValues[i][k];
            // cout << allValues[i][k] << " " << endl;
         }
    }

    vector<int>indexTracker(k,0);
    priority_queue<PAIR, vector<PAIR>, greater<PAIR> > PQ;
    // Initialization of PQ
    for( int i = 0; i < k; i++ ){
        PQ.push(make_pair(allValues[i][0], indexTracker[i]));
    }
    
    vector<int>ans;
    // Main Logic of Heap
    while( !PQ.empty() ){   
        
        PAIR x = PQ.top();
        PQ.pop();
        ans.push_back( x.first );
        if( indexTracker[x.second] + 1  < allValues[x.second].size() ){ // Increment Position Validity Check
            PQ.push( make_pair(allValues[x.second][indexTracker[x.second] + 1 ], x.second)); 
            // We are creating a Pair : ( increment position , increment position array identity )
            // Push in PQ 
        }
        indexTracker[x.second] + 1;
    }
    // Print Answer 
    for( auto element : ans ){
        cout << element << " ";
    }

    return 0;
}

/* 
    3 ---< K Of Array
    3 ---> first of array size
    1 4 7 -> element of first array size
    2 ---> second of array size
    3 5 --> element of second array size
    3 ---> third array size
    2 6 7 --> element of third array size

    input Format of array
3
3
1 4 7
2
3 5
3
2 6 7

 */