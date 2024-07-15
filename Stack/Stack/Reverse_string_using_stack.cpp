#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main()
{
    string str = "Subhan";

    stack <char> s1;

    for (int i = 0; i < str.length(); i++)
    {
        char c = str[i];
        s1.push(c);
    }

    while(!s1.empty())
    {
        cout<<s1.top();
        s1.pop();
    }
    
    
    return 0;
}