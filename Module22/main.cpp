#include<bits/stdc++.h>
#include"MYSTACK.h"

using namespace std;
/* 
    Stack Of Float, double , char, String , array, Structure 
    object of Class     
 */
int main(){
    Stack st;
    st.push(1);
    st.push(2);
    st.push(3);

    while( !st.empty() ){
        cout <<  st.pop() << endl;
    }

    cout << st.size() << endl;
    if( !st.empty() ) cout << st.Top() << endl; // st.Top() != -1
    return 0;
}