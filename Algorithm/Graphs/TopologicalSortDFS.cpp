#include<bits/stdc++.h>
using namespace std;

template<typename T>
class Graph{
    map<T,list<T>> adjList;
    public: 
    void addEdge(T u, T v){
        adjList[u].push_back(v);
    }
    void dfsHelper(map<T,bool> &visited, stack<T> &s, T node){
        visited[node] = true;

        for(auto neighbour : adjList[node]){
            if(!visited[neighbour]){
                dfsHelper(visited,s,neighbour);
            }
        }
        // At this point all the neighbour of node is visited then push it to the stack
        s.push(node);
    }
    void print(stack<T> s){
        while(!s.empty()){
            cout << s.top() << "->";
            s.pop();
        }
    }
    void topologicalSort(){
        map<T,bool> visited;
        stack<T> s;
        for(auto i : adjList){
            if(!visited[i.first]){
                dfsHelper(visited,s,i.first);
            }
        }
        print(s);
    }
};

int main() {
    Graph<int> g;
    g.addEdge(0,1);
    g.addEdge(0,4);
    g.addEdge(1,2);
    g.addEdge(2,4);
    g.addEdge(4,3);
    g.addEdge(2,3);
    g.addEdge(3,5);

    g.topologicalSort();


    return 0;
}