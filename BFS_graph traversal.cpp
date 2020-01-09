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
			map<T,bool> visited;
			q.push(src);
			visited[src] = true;
			while(!q.empty())
			{
				T node = q.front();  //here node is just a variable representing the number
				cout<<node<<" ";
				q.pop();
				
				//For the neighbours  of the current node,find out th children
				for(int neighbout:adjList[node])
				{
					if(!visited[neighbour]){
						q.push(neighbour);
						visited[neighbour] = true;
					}
				}
				
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
