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
			int component=1;
			
			dfshelper(src,visited);
			cout<<endl;
			
			for(auto i:adjList){
				T city=i.first;
				if(!visited[city]){
					dfshelper(city,visited);
					component++;
				}
			}
			cout<<"The current graph had "<<component<<" components";
		}
};
int  main(){
	Graph<string> g;
	g.addedge("Amritsar" , "Jaipur");
	g.addedge("Amritsar" , "Delhi");
	g.addedge("Delhi" , "Jaipur");
	g.addedge("Mumbai" , "Jaipur");
	g.addedge("Mumbai","Bhopal");
    g.addedge("Delhi" , "Bhopal");
    g.addedge("Mumbai" , "Bangalore");
	g.addedge("Agra" , "Delhi");
	g.addedge("Andaman" , "Nicobar");
	g.dfs("Amritsar");
	return 0;	
	
}
