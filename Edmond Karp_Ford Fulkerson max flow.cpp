//using adjacency matrix to represent graph(each edge's weight) and implement edmond karp algorithm using BFS 
//to find all the augmented paths
#include <bits/stdc++.h>
using namespace std;

bool bfs(int **residualCapacity,int source,int sink,int n,int *parent){
    //n-no of vertices
    //parent array to denote parent of each vertex
    bool visited[n];
    memset(visited,0,sizeof(visited));  //to initialise each value in the visted array as false
    queue <int> q;
    visited[source]=true;
    q.push(source);
    bool foundAugmentedPath = false;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(int v=0;v<n;v++){
            //v-current vertex selected to be checked for finding the next vertex in the augmented path
            if(visited[v] == false && residualCapacity[u][v] > 0){
                parent[v]=u;
                visited[v]=true;
                q.push(v);
                if(v==sink){
                    foundAugmentedPath = true;
                    break;
                }
            }
        }
    }
    return foundAugmentedPath;
}

void printAugmentedPaths(vector<vector<int>> augmentedPaths){
    for(int i=0;i<augmentedPaths.size();i++){
        for(int j=0;j<augmentedPaths[i].size();j++){
            cout<<augmentedPaths[i][j]<<"-->";
        } 
        cout<<endl;
    }
}

int maxFlow(int **capacity,int source,int sink,int v){
    //v-no of vertices
    int **residualCapacity = new int*[v];
    for(int i=0;i<v;i++){
        residualCapacity[i] = new int[v];
    }
    //initialising residual_capacity matrix with the original capacity of edges of the graph
    for(int i=0;i<v;i++){
        for(int j=0;j<v;j++){
            residualCapacity[i][j] = capacity[i][j];
        }
    }
    int *parent = new int[1000];
    vector<vector<int>> augmentedPaths;
    int maxFlow = 0;
    while(bfs(residualCapacity,source,sink,v,parent)){
        vector<int> currentAugmentedPath;
        int flow = INT_MAX;
        int v = sink;
        while(v!=source){
            //we will backtrace our path from sink to source and store the minimum flow of any edge in the path in the flow variable
            currentAugmentedPath.push_back(v);
            int u = parent[v];
            if(flow > residualCapacity[u][v]){
                flow = residualCapacity[u][v];
            }
            v=u;
        }
        currentAugmentedPath.push_back(source);
        std::reverse(currentAugmentedPath.begin(),currentAugmentedPath.end());
        augmentedPaths.push_back(currentAugmentedPath);
        maxFlow += flow;

        v=sink;
        while(v!=source){
            int u=parent[v];
            residualCapacity[u][v]-=flow;
            residualCapacity[v][u]+=flow;
            v=u;
        }
    }
    printAugmentedPaths(augmentedPaths);
    return maxFlow;
}

int main() {
    int v,e;  //v-no of vertices, e-no of edges 
    cin>>v>>e;
    int **capacity = new int*[v];  //adjacency matrix 
    for(int i=0;i<v;i++){
        capacity[i]= new int[v];
    }
    for(int i=0;i<e;i++){
        int u,v,c;  //c-weight/capacity of each edge
        cin>>u>>v>>c;
        capacity[u][v] = c;
    }
    cout<<maxFlow(capacity,0,1,v);
    
    return 0;
}
