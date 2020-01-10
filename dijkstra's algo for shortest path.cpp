#include<bits/stdc++.h>
using namespace std;
template<typename T>
class Graph{
	unordered_map<T,list<pair<T,int> > > m;
	public:
		void addEdge(T u,T v,int dist,bool bidir=true){
			m[u].push_back(make_pair(v,dist));
			if(bidir)
			{
				m[v].push_back(mak_pair(u,dist));
			}
			
		}
	    void printAdj(){
	    	//Let try to print adj list
	    	//iterate over all the key value pairs in the mao
	    	for(auto j:m){
	    		cout<<j.first<<"->";
	    		//iterate over the list of cities
	    		for(auto l:j.second){
	    			cout<<"("<<l.first<<" , "<<l.second<<")";
				}
				cout<<endl;
			}
		}
        void dijsktraSSSP(T src){
        	unordered_map<T,int> dist;
        	//Set all distances to infinity
        	for(auto j:m){
        		dist[j.first] = INT_MAX;
			}
			//make a set to find a out node with the inimum distance
			set<pair<int,T> >s;   //first element taken as distance because set is by default sorted according to first element
			dist[src] = 0;
			s.insert(make_pair(0,src));
			while(!s.empty()){
				//Find the pair at the front.
				auto p = *(s.begin());
				T node = p.second;
			    int nodeDist = p.first;
			    s.erase(s.begin());
			    
			    //iterate ovr neighbours/children of the current node
			    for(auto childPair: m[node]){
			    	if(nodeDist + childPair.second < dist[childPair.first]){
			    		//in the set updation of a particular is not possible
			    		//we ahve to remove the old pair,a nd insert the new pair to simulate updation
			    		
						T dest =childPair.first;
						auto f=s.find(make_pair(dist[dest],dest));
						if(f!=s.end()){
							s.erase(f);
						}
						//insert the new pair
						dist[dest]  = nodeDist + childPair.second;
						s.insert(amke_pair(dist[dest],dest));
					}
				}
			
			}
			
		}	
};
int main()
{
	Graph<int> g;
	g.addEdge(1,2,1);
	g.addEdge(1,3,4);
	g.addEdge(2,3,1);
	g.addEdge(3,4,2);
	g.addEdge(1,4,7);
	g.printAdj();
	g.dijsktraSSSP(1);
	return 0;
}
