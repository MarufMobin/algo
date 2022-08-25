#include <bits/stdc++.h>
#include "MYSTACK.h"
using namespace std;

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
    // int result = prefixEvaluation("+*423") ;
    int result = prefixEvaluation("-+7*45+20");
    cout << result << endl ;
    return 0;
}