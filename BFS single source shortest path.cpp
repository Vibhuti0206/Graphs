#include<bits/stdc++.h>
using namespace std;
template<typename T>
class Graph{
	map<T,list<T> > adjList;
	public:
		Graph()
		{
			
		}
		void addedge(T u,T v,bool bidir=true)
		{
			adjList[u].push_back(v);
			if(bidir)
			{
				adjList[v].push_back(u);
			}
		}
		void print()
		{
			//Iterate over the map
			for(auto i:adjList)
			{
				cout<<i.first<<"->";
				//i.second is linked list
				
				for(T entry:i.second){     //or cab be written as for(auto entry:i.second);auto automatically determines the type of data
					cout<<entry<<" , ";
				}
				cout<<endl;
				
			}
		}
		void bfs(T src)
		{
			queue<T> q;
			map<T,int> dist;
			map<T,T> parent;
			for(auto i:adjList){
				dist[i.first] = INT_MAX;   //initially all distances are -infinity
			}
			q.push(src);
			dist[src] = 0;
			parent[src] = src;
			while(!q.empty())
			{
				T node = q.front();  //here node is just a variable representing the number
				cout<<node<<" ";
				q.pop();
				
				//For the neighbours  of the current node,find out th children
				for(int neighbour:adjList[node])
				{
					if(dist[neighbour] ==INT_MAX){
						q.push(neighbour);
						dist[neighbour] = dist[node] + 1;
						parent[neighbour] = node;
					}
				}
				
			}
			//Print the distance to all nodes
			for(auto i:adjList){
				T node = i.first;
				cout<<"Dist of "<<node<<" from "<<src<<" is "<<dist[node]<<endl;
			}
		}
};
int  main(){
	Graph<int> g;
	g.addedge(0,1);
	g.addedge(1,2);
	g.addedge(0,4);
	g.addedge(2,4);
	g.addedge(2,3);
    g.addedge(3,5);
    g.addedge(3,4);
	g.bfs(0);
	return 0;	
	
}
