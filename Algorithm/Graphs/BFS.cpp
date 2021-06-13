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
    
    void print(){
        for(auto i : adjList){
            cout << i.first << "=>";
            for(auto neighbour: i.second){
                cout << neighbour << ",";
            }
            cout << "\n";
        }
    }
    
    void bfs(T src){
        queue<T> q;
        map<T,bool> visited;
        q.push(src);
        visited[src] = true;
        while(!q.empty()){
            T node = q.front();
            q.pop();
            cout << node << ",";
            // Traverse the neighbour of that node and marked them visited
            for(auto neighbour : adjList[node]){
                if(!visited[neighbour]){
                    q.push(neighbour);
                    visited[neighbour] = true;
                }
            }
        }
    }

    // Calculate Single source shortest path in unweighted graph
    void ssspUnweightedGraph(T src){
        queue<T> q;
        map<T,int> distance;
        map<T,T> parent;
        for(auto i : adjList){
            distance[i.first] = INT_MAX;
        }
        distance[src] = 0;
        parent[src] = src;
        q.push(src);

        while(!q.empty()){
            T node = q.front();
            q.pop();
            for(auto neighbour : adjList[node]){
                if(distance[neighbour] == INT_MAX){
                    q.push(neighbour);
                    distance[neighbour] = distance[node]+1;
                    parent[neighbour] = node;
                }
            }
        }
        for(auto i : adjList){
            T node = i.first;
            cout << "Distance of " << node << " from " << src << " is " << distance[node] << "\n";
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

    g.print();
    g.bfs(0);
    g.ssspUnweightedGraph(0);
}