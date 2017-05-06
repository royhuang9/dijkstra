#include <iostream>
#include "Graph.h"
#include "ShortestPath.h"

using namespace std;
int main(void)
{
	Graph g(7);
	/*"Shanghai", "Beijing", "Nanjing","Zhengzhou", "Tianjin", "Jinan", "Xuzhou"*/
	g.add_edge("Shanghai", "Beijing", 100.0);
	g.add_edge("Shanghai", "Nanjing", 20.0);
	g.add_edge("Beijing", "Zhengzhou", 30.0);
	g.add_edge("Nanjing", "Zhengzhou", 50.0);
	g.add_edge("Beijing", "Tianjin", 10.0);
	g.add_edge("Tianjin", "Jinan", 40.0);
	g.add_edge("Jinan", "Shanghai", 80.0);
	g.add_edge("Jinan", "Xuzhou", 30.0);
	g.add_edge("Xuzhou", "Zhengzhou", 20.0);
	g.add_edge("Xuzhou", "Nanjing", 40.0);
	g.add_edge("Xuzhou", "Shanghai", 50.0);


	ShortestPath sp;
	float dist=sp.dijkstra(g, "Shanghai", "Zhengzhou");
	cout << dist << endl;

	vector<string> short_path = sp.path();

	for (const string &name : short_path)
		cout << name << "" << endl;

}