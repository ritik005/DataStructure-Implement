#include<bits/stdc++.h>
using namespace std;

/* For undirected Graph we use BFS to detect the cycle.
We maintain parent array and visited array,
if the particular neighbour of a node is visited and 
the neighbour is not the parent of the node, then cycle is present
else not.
*/

template<typename T>
class Graph{
    map<T,list<T>> adjList;
    public: 
    void addEdge(T u, T v){
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
    bool cycleDetect(T src){
        map<T,bool> visited;
        map<T,T> parent;
        queue<T> q;
        visited[src] = true;
        parent[src] = src;
        q.push(src);
        while(!q.empty()){
            T node = q.front();
            q.pop();
            for(auto neighbour: adjList[node]){
                if(visited[neighbour] == true && parent[node]!=neighbour) return true;
                else if(!visited[neighbour]){
                    visited[neighbour] = true;
                    parent[neighbour] = node;
                    q.push(neighbour);
                }
            }
        }
        return false;
    }
};

int main(){
    Graph<int> g;
    g.addEdge(0,1);
    g.addEdge(0,4);
    g.addEdge(1,2);
    g.addEdge(2,4);
    g.addEdge(4,3);
    g.addEdge(2,3);
    g.addEdge(3,5);

    (g.cycleDetect(0))?cout << "Present": cout << "Not Present";

    return 0;
}