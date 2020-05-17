#include <iostream>
#include <stack>
using namespace std;

bool checkParan(string str){
    stack <char> s;
    for(int i = 0; i < str.size(); i++){
        if(str[i] == '('){
            s.push(str[i]);
        }
        else if(str[i] == ')'){
            if(s.empty() || s.top()!='('){
                return false;
            }
            s.pop();
        }
    }
    return s.empty();
}

int main(){
    string str;
    cin >> str;
    bool isValid = checkParan(str);
    cout << isValid;
    return 0;
}