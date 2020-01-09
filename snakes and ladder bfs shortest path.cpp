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
		int bfs(T src,T dest)
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
				//cout<<node<<" ";
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
			//You can destination and go backwards
			T temp=dest;
			while(temp!=src){
				cout<<temp<<" <-- ";
				temp = parent[temp];
			}
			cout<<src<<endl;
			return dist[dest];
		}
};
int  main(){
	Graph<int> g;
	int board[50] = {0};
	board[2]=13;
	board[5]=2;
	board[9]=18;
	board[18]=11;
	board[17]=-13;
	board[20]=-14;
	board[24]=-8;
	board[25]=-10;
	board[32]=-2;
	board[34]=-22;
	//Lets first construct the graph,add pairs of u,v;
	for(int u=0;u<=36;u++)
	{
		//At every node,you can throw a dice
		for(int dice=1;dice<=6;dice++)
		{
			int v=u+dice+board[u+dice];
			g.addedge(u,v,false);
		}
	}
	cout<<"The shortest distance is"<<g.bfs(1,36)<<endl;
	return 0;	
	
}
