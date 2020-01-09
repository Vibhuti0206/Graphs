#include<bits/stc++.h>
using namespace std;
class Graph{
	int V;
	list<int> *l;  //Just like we do dynmaic allocation of integers int *n; here it is list of integers;
	public:
		Graph(int v)
		{
			V=v;
			//Array of linked list
			l = new list<int>[V];
			
		}
		void addedge(int u,int v,bool bidir=true){
			l[u].push_back(v);
			if(bidir)
			{
				l[v].push_back(u);
			}
		}
		
		void printAdjList()
		{
			for(int i=0;i<V;i++)
			{
				cout<<i<<"->";
				//l[i] is a linked list
				for(int vertex:l[i]){
					cout<<vertex<<" , ";
				}
			}
		}
};
int main()
{
	//Graph has 5 vertices number from 0 to 4
	Graph g(5);
	g.addedge(0,1);
	g.addedge(0,4);
	g.addedge(4,3);
	g.addedge(1,4);
	g.addedge(1,2);
	g.addedge(2,3);
	g.printAdjList();
	
	return 0;
