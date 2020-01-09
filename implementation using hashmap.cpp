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
};
int  main(){
	Graph<string> g;
	g.addedge("Putin","trump",false);
	g.addedge("Putin","modi",false);
	g.addedge("Putin","pope",false);
	g.addedge("modi","trump",false);
	g.addedge("modi","yogi",false);
	g.addedge("yogi","prabhu",false);
	g.addedge("prabhu","modi",false);
	g.print();
	return 0;	
	
}
