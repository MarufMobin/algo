#include <bits/stdc++.h>
#include "MYSTACK.h"

using namespace std;
bool balanceParanthesis(string s)
{
    int n = s.size();
    Stack<char> st;
    bool isBalance = true;
    if (s[0] == ')' || s[0] == '}' || s[0] == ']')
    {
        return false;
    }
    for (int i = 0; i < n; i++)
    {
        // Opening Bracket ---> ( , { , [
        if (s[i] == '(' || s[i] == '{' || s[i] == '[' )
        {
            st.push(s[i]);
        }
        // Check First Bracket
        //  ) ---> st.top == ( st.pop else isBalance = false break
        else if (s[i] == ')')
        {
            if (st.Top() == '(')
            {
                st.pop();
            }
            else
            {
                isBalance = false;
                break;
            }
        }
        //  } ---> st.top == {  st.pop else isBalance = false break
        else if (s[i] == '}')
        {
            if (st.Top() == '{')
            {
                st.pop();
            }
            else
            {
                isBalance = false;
                break;
            }
        }
        //  [ ---> st.top ==  ] st.pop else isBalance = false break
        else if (s[i] == ']')
        {
            if (st.Top() == '[')
            {
                st.pop();
            }
            else
            {
                isBalance = false;
                break;
            }
        }
    }
    if (!st.empty())
    {
        isBalance = false;
    }
    return isBalance;
}
int main()
{
    string chk;
    cin >> chk;
    if (balanceParanthesis(chk))
        cout << "YES";
    else
        cout << "NO";
    return 0;
}