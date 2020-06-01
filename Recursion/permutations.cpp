#include <iostream>

using namespace std;

void sequence(char* in , int i ){
    if(in[i] == '\0'){
        cout << in <<", ";
        return;
    }
    for(int j = i; in[j]!='\0'; j++){
        swap(in[i], in[j]);
        sequence(in,i+1);
        // Backtrackng
        swap(in[i],in[j]);
    }
}
int main(){
    char in[100] ="abc";
    sequence(in,0);
    return 0; 
}