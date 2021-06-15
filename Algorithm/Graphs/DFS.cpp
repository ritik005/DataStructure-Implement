#include<bits/stdc++.h>
using namespace std;

template<typename T>
class Graph{
    map<T,list<T>> adjList;
    public:
    void addEdge(T u, T v, bool bidirected = true){
        adjList[u].push_back(v);
        if(bidirected) adjList[v].push_back(u);
    }
    
    void dfsHelper(map<T,bool>& visited, T node){
        cout << node << ",";
        visited[node] = true;
        for(auto neighbour : adjList[node]){
            if(!visited[neighbour])
            {
                dfsHelper(visited,neighbour);
            }
        }
    }
    // Dfs for connected components
    void dfs(T src){
        map<T,bool> visited;
        dfsHelper(visited,src);
        for(auto i : adjList){
            if(!visited[i.first]){
                dfsHelper(visited,i.first);
            }
        }
    }
    
};

int main(){
    Graph<int> g;
    g.addEdge(0,1,true);
    g.addEdge(0,4,true);
    g.addEdge(1,2,true);
    g.addEdge(2,4,true);
    g.addEdge(4,3,true);
    g.addEdge(2,3,true);
    g.addEdge(3,5,true);
    g.dfs(0);
    
}