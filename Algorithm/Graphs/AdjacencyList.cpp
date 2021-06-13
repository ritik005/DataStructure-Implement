#include<bits/stdc++.h>
using namespace std;

void addEdge(map<int,vector<int> > &m, int u, int v, bool bidirected=true){
 m[u].push_back(v);
 if(bidirected) m[v].push_back(u);
};

void print(map<int,vector<int> > m){

 for(auto x : m){
  cout << x.first <<"->";
  for(auto neighbour : x.second){
      cout << neighbour << ",";
  }
 cout << endl;
 }
};



int main(){
 map<int,vector<int> > m;
 addEdge(m,0,1,true);
 addEdge(m,0,2,true);
 addEdge(m,1,3,true);
 addEdge(m,3,2,true);
 addEdge(m,3,4,true);
 addEdge(m,4,2,true);
 addEdge(m,4,5,true);

 print(m);
}