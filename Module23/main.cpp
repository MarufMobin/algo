#include<bits/stdc++.h>
#include"MYSTACK.h"

using namespace std;
/* 
    Stack Of Float, double , char, String , array, Structure , pair
    object of Class     
 */
int main(){
    //Pair Data Type 

    Stack < pair<int, char> > st;
    st.push(make_pair(1, 'Maruf'));
    st.push(make_pair(2, 'Munna'));
    st.push(make_pair(3, 'jabbar'));

    // Stack <string> st;
    // st.push("Maruf");
    // st.push("Munna");
    // st.push("Jabbar");

    // Stack <int> st;
    // st.push(1);
    // st.push(3);
    // st.push(6);
    
    // Stack <float> st;
    // st.push(1.2);
    // st.push(3.4);
    // st.push(33.2);

    // while( !st.empty() ){
    //     cout <<  st.pop() << endl;
    // }

    while( !st.empty() ){
        pair <int, char> chk;
        chk = st.pop();
        cout <<  chk.first << " | " << chk.second << endl;
    }

    cout << st.size() << endl;
    // if( !st.empty() ) cout << st.Top() << endl; // st.Top() != -1

    if( !st.empty() ) {
        pair <int , char > chk;
        chk = st.Top();
        cout <<  chk.first << " | " << chk.second << endl;
    }
    return 0;
}