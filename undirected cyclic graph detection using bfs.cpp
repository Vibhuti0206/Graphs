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
	//Check for undirected graph
	bool iscyclic(T src)
	{
		map<T,bool> visited;
		map<T,int> parent;
		queue<T> q;
		q.push(src);
		visited[src]  = true;
		parent[src] = src;
		while(!q.empty()){
			T node = q.front();
			q.pop();
			
			//iterate over the neigbours of that node leaving parent.
			for(T neighbour:adjList[node]){
				if(visited[neighbour] = true && parent[node]!=neighbour){
					return true;
				}
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
int  main(){
	Graph<int> g;

	g.addedge(1,2);
	g.addedge(1,4);

	g.addedge(4,3);
   
    g.addedge(2,3);
	if(g.iscyclic(1))
	   cout<<"Cyclic Graph";
	else
	   cout<<"Not Cyclic Graph";
	return 0;	
	
}
