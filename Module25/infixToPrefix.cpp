#include <bits/stdc++.h>
#include "MYSTACK.h"
using namespace std;

//Precision Calculation 
int precisionCalc( char c ){
    if( c == '^' ) return 3;
    else if ( c == '/' || c == '*' ) return 2;
    else if( c == '+' || c == '-' ) return 1;
    else   return -1;
}

//Infix to Prefix
string infixToPrefix( string chk ){
    reverse( chk.begin(), chk.end());
    Stack<char>st;
    string result;

    for( int i = 0; i < chk.length(); i++ ){
        if( chk[i] >= '0' && chk[i] <= '9' ) {
            result += chk[i];
        }
        else if( chk[i] == ')' ){
            st.push(chk[i] );
        }
        else if( chk[i] == '(' ){
            while( !st.empty() && st.Top() != ')' ){
                result += st.pop();
            }
            if( !st.empty() ) st.pop();
        }
        else{
            while( !st.empty() && precisionCalc( st.Top() ) >= precisionCalc( chk[i] ) ){
                result += st.pop();
            }
            st.push(chk[i]);
        }
    }
    
    while( !st.empty() ){
        result+= st.pop();
    }

    reverse( result.begin(), result.end() );
    return result;
}
// Prefix Evaluaction
int prefixEvaluation(string chk)
{
    Stack<int> st;
    for (int i = chk.length(); i >= 0; i--)
    {
        if (chk[i] >= '0' && chk[i] <= '9') // Chk i = 0 to 9  ---> Operand
        {
            st.push(chk[i] - '0'); // ( int ) or '0'
        }
        else // Chk[i] ----> Operator
        {
            int a = st.pop();
            int b = st.pop();

            switch (chk[i])
            {
            case '+':
                st.push(a + b);
                break;
            case '-':
                st.push(a - b);
                break;
            case '*':
                st.push(a * b);
                break;
            case '/':
                st.push(a / b);
                break;
            case '^':
                st.push(pow(a, b));
                break;
            default:
                break;
            }
        }
    }
    return st.Top();
}

int main()
{
    string infix = "(7+(4*5))-(2+0)";
    string prefix;
    prefix = infixToPrefix(infix);
    cout << endl << prefix << endl;
    // int result = prefixEvaluation("+*423") ;
    int result = prefixEvaluation("-+7*45+20");
    cout << result << endl ;
    return 0;
}