#include<bits/stdc++.h>
using namespace std;

template<typename T>
class Graph{
    map<T,list<pair<T,int>>> adjList;
    public: 

    void addEdge(T u, T v, int dist, bool bidirected = true){
        adjList[u].push_back(make_pair(v,dist));
        if(bidirected)adjList[v].push_back(make_pair(u,dist));
    }
    void dijkstraAlgo(T src){
        map<T,int> dist;
        // Initialize the distance of each node to infinity.
        for(auto i : adjList){
            dist[i.first] = INT_MAX;
        }
        // We will maintain a set to find out the node with minimum distance from
        set<pair<int,T>> s;
        dist[src] = 0;
        s.insert(make_pair(0,src));

        while(!s.empty()){
            //find the pair at the front
            auto p = *(s.begin());
            T node = p.second;
            int nodeDist = p.first;
            s.erase(s.begin());

            // Iterate over children/neighbour of the node;
            for(auto neighbour : adjList[node]){
                if((nodeDist + neighbour.second) < dist[neighbour.first]){
                    /*In set, updation of a particular element is not possible.
                    we have to remove the old pair and insert the new pair to stimulate updation
                    */
                   T destinationNode = neighbour.first;
                   auto f = s.find(make_pair(dist[destinationNode],destinationNode));
                   if(f!=s.end()){
                       s.erase(f);
                   }
                   // insert the new pair
                   dist[destinationNode] = nodeDist+neighbour.second;
                   s.insert(make_pair(dist[destinationNode],destinationNode));
                }
            }
        }
        for(auto i : dist){
            cout << "Distance of node " << i.first << " is " << i.second << "\n";
        }
    }
};

int main(){
    Graph<int> g;
    g.addEdge(0,1,1,true);
    g.addEdge(0,2,1,true);
    g.addEdge(1,3,2,true);
    g.addEdge(2,3,2,true);
    g.addEdge(2,4,1,true);
    g.addEdge(3,4,2,true);

    g.dijkstraAlgo(0);

    return 0;
}
