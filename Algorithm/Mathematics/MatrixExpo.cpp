#include<iostream>
#define N 51
#define m 1000000007
#define ll long long
using namespace std;

ll arr[N][N], In[N][N];

void mul(ll A[][N], ll B[][N], ll dim ){
    ll res[dim+1][dim+1];
    //Multiplication of two matrix
    for(ll i = 1; i <= dim; i++){
        for(ll j = 1; j <= dim ; j++){
            res[i][j] = 0;
            for(ll k = 1; k <= dim; k++){
                res[i][j] = (res[i][j]%m +  A[i][k]%m * B[k][j]%m)%m;
            }
        }
    }
        for(ll i = 1; i<= dim; i++){
            for(ll j = 1; j <= dim; j++){
                A[i][j] = res[i][j];
            }
        }
}

void power(ll A[][N], ll dim, ll n){
    // create identity matrix
    for(ll i = 1; i <= dim; i++){
        for(ll j = 1; j <= dim; j++){
            if(i == j) In[i][j] = 1;
            else In[i][j] = 0;
        }
    }
    // for(ll i = 1; i <= n; i++){
    //     mul(In, A, dim);
    while(n){
        if(n%2){
            mul(In,A,dim); n--;
        } else{
            mul(A,A,dim); n /= 2;
        }
    }
    for(ll i = 1; i <= dim; i++){
        for(ll j = 1; j <= dim; j++){
            A[i][j] = In[i][j];
        }
    }
}

void print(ll A[][N], ll dim){
    for(ll i = 1; i <= dim; i++){
        for(ll j = 1; j <= dim; j++){
            cout << A[i][j] << " ";
        }
        cout << "\n";
    }
}

int main(){
    ll t,dim,n;
    cin >> t;
    while(t--){
        cin >> dim >> n;
        for(ll i = 1; i<= dim; i++){
            for(ll j = 1; j <= dim; j++){
                cin >> arr[i][j];
            }
        }
        power(arr, dim, n);
        print(arr,dim);
    }
    
}