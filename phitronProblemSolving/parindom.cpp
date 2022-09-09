// #include<bits/stdc++.h>
// using namespace std;
// string isPalindrom( string s ){
//     string r = s;
//     reverse( r.begin(), r.end() );
//     if( r == s ) return "YES";
//     else return "NO";
// }
// int main(){
//     int n;
//     cin >> n;
//     char s[n];
//     for( int i = 0; i < n; i++ ){
//         cin >> s[i];
//     }
//     cout << isPalindrom( s );
//     return 0;
// }

// #include<bits/stdc++.h>
// using namespace std;

// int main(){
//     int n;
//     cin >> n;
//     char ch[n];
//     for( int i = 0; i < n; i++ ){
//         cin >> ch[i];
//     }
//     char rvCh[n];
//     int j = 0, k = n-1; 
//     for( int i = n-1; i >= 0; i-- ){
//         rvCh[j] = ch[i];
//         j++;
//     }
//     cout << rvCh;
//     if( ch == rvCh ) cout << "NO";
//     else cout << "YES";
//     return 0;
// }

#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    char ch[n];
    for( int i = 0; i < n; i++ ){
        cin >> ch[i];
    }
    int j = 0;
    char rev[n];
    for( int i = n-1; i >= 0; i-- ){
        rev[j] = ch[i];
        j++;
    }    
    
    for( int i = 0; i < n; i++ ){
        if( rev[i] != ch[i] ){
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";
    return 0;
}