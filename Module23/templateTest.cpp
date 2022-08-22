#include<bits/stdc++.h>
using namespace std;
template<typename T> T myMax( T a , T b ){
    return ( a > b ) ? a : b;
}
int main(){
    
    cout << myMax<int>( 3, 5 ) << endl;
    cout << myMax<float>( 3.3, 7.4 ) << endl;
    cout << myMax<char>( 'a', 'r' ) << endl;

    return 0;
}