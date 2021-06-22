#include<bits/stdc++.h>
using namespace std;
template<typename T>
class Graph{
    map<T,list<T>> adjList;
    public:
    void addEdge(T u, T v){
        adjList[u].push_back(v);
    }
    void topoBFS(){
        map<T,int> indegree;
        queue<T> q;

        // initialize 0 to all the indegree of a nodes
        for(auto i : adjList){
            T node = i.first;
            indegree[node] = 0;
        }
        //Calculating indegree of each node;
        for(auto i : adjList){
            T node = i.first;
            for(auto neighbour : adjList[node]){
                indegree[neighbour]++;
            }
        }
        // Push all the node with 0 indegree in the queue
        for(auto i : adjList){
            T node = i.first;
            if(indegree[node] == 0){
                q.push(node);
            }
        }

        while(!q.empty()){
            T node = q.front();
            q.pop();
            cout << node << "->";
            for(auto i : adjList[node]){
                indegree[i]--;
                if(indegree[i]==0){
                    q.push(i);
                }
            }
        }
        
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
    g.topoBFS();

}