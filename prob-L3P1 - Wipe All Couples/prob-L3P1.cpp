#include <iostream>
#include <stack>
using namespace std;

int main(){
    int i;
    string c;
    stack <char> s; 
    stack <char> a;
    cin >> c;

    for(i=0; i<c.length(); i++){
        s.push(c[i]);
    }

    for(i=0; i<c.length(); i++){
        if(!a.empty()){
            if(a.top() == s.top() && !a.empty())
            {
                a.pop();
                s.pop();
            }
            else{
            a.push(s.top());
            s.pop();
            }
        }
        else{
            a.push(s.top());
            s.pop();
        }
    }

    while(!a.empty()){
        cout << a.top();
        a.pop();
    }

}