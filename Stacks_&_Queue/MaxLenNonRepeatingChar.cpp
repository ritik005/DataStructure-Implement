#include <iostream>
#include <math.h>
#include <cstring>
using namespace std;

int main(){
    char a[] = "abcdedtfghrtyu";
    int n = strlen(a);
    int current_len = 1;
    int max_len = 1;
    int visited[256] = {-1};
    visited[a[0]] = 0;
    for(int i = 1; i < n; i++){
        int last_occur = visited[a[i]];

        if(last_occur == -1 || i - current_len > last_occur){
            current_len += 1;
            max_len = max(current_len, max_len);
        }
        else{
            if(current_len > max_len){
                max_len = current_len;
            }
            current_len = i - last_occur;
        }
        visited[a[i]] = i;
    }
    if(current_len > max_len){
        max_len = current_len;
    }
    cout << max_len;
    return 0;
}