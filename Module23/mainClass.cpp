#include<bits/stdc++.h>
#include"MYSTACK.h"

using namespace std;
int globalId = 100;
class person
{
    string name;
    int id;
    float salary;

public:
    //  Null Constractor 
    person()
    {
        name = "";
        id = -1;
        salary = -1;
    }
    void setName( string name ){
        this->name = name;
    }
    void setSalary( float salary ){
        this->salary = salary;
    }
    person(string name, float salary)
    {
        setName(name);
        setSalary(salary);
        id = globalId;
        globalId++;
    }
    int getID(){
        return id;
    }
    string getName(){
        return name;
    }
    float getSalary(){
        return salary;  
    }
    void print(){
        cout << name << " | " << id << " | " << salary << endl;
    }
};
int main()
{
    Stack <person> st;

    person a ("Maruf", 3610.2 );
    person b ( "Jabbar", 3234.3 );
    person c ("Munna", 21232.22 );

    st.push(a);
    st.push(b);
    st.push(c);

    // while ( !st.empty() )
    // {
    //     person printObj;
    //     printObj = st.pop();
    //     cout << endl;
    //     printObj.print();

    // }
        person printObj;
        printObj = st.Top();;
        cout << endl;
        printObj.print();
    
        st.size();
    return 0;
}