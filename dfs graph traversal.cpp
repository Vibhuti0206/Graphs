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
		void dfshelper(T node,map<T,bool> &visited)
		{
			//whenever to come to a node,mark it visitedd
			visited[node] = true;
			cout<<node<<" ";
			//try to find out a node which is neigbour of currrent node and not yet visited
			for(T neigbour:adjList[node])
			{
				if(!visited[neigbour])
				{
					dfshelper(neigbour,visited);
				}
			}
		}
		void dfs(T src)
		{
			map<T,bool> visited;
			dfshelper(src,visited);
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
	g.dfs(0);
	return 0;	
	
}
