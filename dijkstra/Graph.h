#pragma once
#include <vector>
#include <map>
#include <string>

#include "node.h"

class Graph
{
public:
	Graph(void);
	~Graph(void);
	explicit Graph(int n);
	Graph(const Graph& that);
	Graph(Graph&& that);
	Graph& operator=(Graph that);
	Graph& operator=(Graph&& that);

	bool add_node(std::string name);
	void add_edge(std::string name1, std::string name2, float weight);

	int get_idx(const std::string &name) {
		if (_vertice_mapping.count(name) == 0)
			return -1;

		return _vertice_mapping[name];
	}

	std::string get_name(const int idx) {
		if (idx >= 0 && idx << _num_node)
			return _vertice_name[idx];

		return std::string();
	}

	std::vector<Node> get_edges(int node_idx);

	int size() {
		return _num_node;
	}

private:
	/* store map matrix, in order to use the STL priority_queue */
	//std::vector<std::vector<float>> weights_map;

	/* In order to practice rule of five, 
	matrices are manually created and maintained */

	float **_weights;

	/* number of nodes */
	int _num_node;

	int _current_node;

	std::vector<std::string> _vertice_name;

	/* mapping of node name and index */
	std::map<std::string, int> _vertice_mapping;
	std::map<int, std::string> _remapping;
};
