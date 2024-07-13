#include <iostream>
#include <string>
#include <string.h>
using namespace std;

// class Parent {
// public:
//     void GeeksforGeeks_Print()
//     {
//         cout << "Base Function" << endl;
//     }
// };

// class Child : public Parent {
// public:
//     void GeeksforGeeks_Print()
//     {
//         cout << "Derived Function" << endl;

//         // call of original function
//         // Parent::GeeksforGeeks_Print();
//     }
// };

// int main()
// {
    // Child Child_Derived;
    // Child_Derived.GeeksforGeeks_Print();
    // Child_Derived.Parent::GeeksforGeeks_Print();
    // return 0;
// }

int main()
{
    string *a = new string[1];
    string str = "Hello World";
    char *s = &str[0];
    char *str = strtok(s, " ");
    while (str != NULL) {
        a[0] = str;
        str = strtok(NULL, " ");
    }
    for (auto i : a) {
        cout<<i<<endl;
    }
    return 0;
}