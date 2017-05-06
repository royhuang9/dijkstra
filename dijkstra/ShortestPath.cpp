#include <vector>
#include <iostream>

#include "ShortestPath.h"

using namespace std;

ShortestPath::ShortestPath(void)
{
}

ShortestPath::~ShortestPath(void)
{
}

float ShortestPath::dijkstra(Graph &g, const string &start, const string &end)
{
	int begin = g.get_idx(start);
	int term = g.get_idx(end);

	if (begin < 0 || term < 0)
		return HUGE_VALF;

	Node first(begin,0,0.0);

	_open_queue.push(first);

	vector<float> dist(g.size(), HUGE_VALF);
	dist[begin] = 0.0;
	while(!_open_queue.empty()) {
		/* get the top element of priority queue */
 		Node top_one = _open_queue.top();
		_open_queue.pop();


		cout << "idx:" << top_one._node_idx << " up:" << top_one._node_up << " w:" << top_one._weight << endl;

		/* check whether it is already in closed set*/
		if (_close_nodes.count(top_one._node_idx) == 1) {
			continue;
		}
		
		_close_nodes[top_one._node_idx] = top_one;

		if (top_one._node_idx == term)
			break;

		int candidate = top_one._node_idx;

		/* Get all downside nodes */
		vector<Node> nodes = g.get_edges(candidate);
		for(Node node: nodes) {
			/* Check whether the node is already in _open_node */
			if (dist[node._node_idx] > dist[candidate] + node._weight) {
				_open_queue.push(node);
				dist[node._node_idx] = dist[candidate] + node._weight;
			}
		}
	}
	for_each(_close_nodes.begin(), _close_nodes.end(),
		[](pair<int, Node> node_map) {cout << "_node_idx:" << node_map.second._node_idx << " up:" << node_map.second._node_up << endl; });

	int temp = term;
	while (temp != begin) {
		_path.push(g.get_name(temp));
		temp = _close_nodes[temp]._node_up;
	}
	_path.push(start);

	return dist[term];
}

vector<std::string> ShortestPath::path()
{
	vector<std::string> p;
	while (!_path.empty()) {
		p.push_back(_path.top());
		_path.pop();
	}
	return p;
}