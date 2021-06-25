#include<bits/stdc++.h>
using namespace std;
/*Bipartite Graph is a graph in which every node is coloured with two colors only
and no two adjacent nodes have same color,
So if odd length cycle is present in the graph then it is not a bipartite graph*/

template<typename T>
class Graph{
    map<T,list<T>> adjList;
    public:
    void addEdge(T u, T v){
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
    bool isBipartiteBFS(){
        map<T,int> color;
        for(auto i : adjList){
            color[i.first] = -1;
        }
        for(auto i : adjList){
            if(color[i.first] == -1){
                if(!checkBipartite(i.first,color)) return false;
            }
        }
        return true;
    }
    bool checkBipartiteBFS(T src, map<T,int> &color){
        queue<T>q;
        q.push(src);
        color[src] = 1;
        while(!q.empty()){
            T node = q.front();
            q.pop();

            for(auto neighbour : adjList[node]){
                if(color[neighbour] == -1){
                    color[neighbour] = 1 - color[node];
                    q.push(neighbour);
                }else if(color[neighbour] == color[node]) return false;
            }
        }
        return true;
    }

    bool isBipartiteDFS(){
        map<T,int> color;
        for(auto i : adjList){
            color[i.first] = -1;
        }
        for(auto i : adjList){
            if(color[i.first] == -1){
                if(!checkBipartiteDFS(i.first,color)) return false;
            }
        }
        return true;
    }
    bool checkBipartiteDFS(T node, map<T,int> &color){
        if(color[node] == -1) color[node] = 1;
        for(auto neighbour : adjList[node]){
            if(color[neighbour] == -1){
                color[neighbour] = 1-color[node];
                if(!checkBipartiteDFS(neighbour,color)) return false;
            }else if(color[neighbour] == color[node]) return false;
        }
        return true;
    }
};

int main(){
    Graph<int>g;
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(3,4);
    g.addEdge(4,5);
    g.addEdge(5,6);
    g.addEdge(5,7);
    g.addEdge(7,8);
    g.addEdge(2,8);

    g.isBipartiteDFS()?cout << "YES" : cout << "NO";


    return 0;
}
