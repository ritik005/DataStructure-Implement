#include<bits/stdc++.h>
using namespace std;
/* For detecting a cycle in directed graph check if thier any back edge present in the graph
if it is present then cycle is present else no*/
template<typename T>
class Graph{
    map<T,list<T>> adjList;
    public: 
    void addEdge(T u, T v){
        adjList[u].push_back(v);
    }

    bool cycleDetect(){
        map<T,bool> visited;
        map<T,bool> instack;

        for(auto i : adjList){
            T node = i.first;
            if(!visited[node]){
                bool cyclePresent = dfsHelper(node,visited,instack);
                 if(cyclePresent) return true;
            }
        }
        return false;
    }
    bool dfsHelper(T node, map<T,bool> &visited, map<T,bool> &instack){
        visited[node] = true;
        instack[node] = true;

        for(auto neighbour : adjList[node]){
            if((!visited[neighbour] && dfsHelper(neighbour, visited, instack)) || instack[neighbour]){ return true;}
        }
        instack[node] = false;
        return false;
    }
};

int main(){
    Graph<int> g;
    g.addEdge(0,1);
    g.addEdge(4,0);
    g.addEdge(1,2);
    g.addEdge(2,4);
    g.addEdge(2,3);
    g.addEdge(3,5);
    g.cycleDetect()? cout << "Present": cout << "Not Present";   
    return 0;
}