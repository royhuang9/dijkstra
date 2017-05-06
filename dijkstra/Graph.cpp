#include "Graph.h"

#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

Graph::Graph(void)
	:_num_node(0)
	,_current_node(0)
	,_weights(nullptr)
{

}

Graph::Graph(int n)
	:_num_node(n)
	,_current_node(0)
	,_weights(new float*[n])
{
	for(int i=0; i<_num_node; i++) {
		_weights[i]=new float[_num_node];
		std::fill(_weights[i], _weights[i] + _num_node, HUGE_VAL);
	}
	_vertice_name.reserve(_num_node);
}

Graph::Graph(const Graph& that)
	:_num_node(that._num_node)
	,_current_node(0)
	, _weights(new float*[_num_node])
	, _vertice_mapping(that._vertice_mapping)
	, _vertice_name(that._vertice_name)
{
	for(int i=0; i<_num_node; i++) {
		_weights[i]=new float[_num_node];
		std::copy(that._weights[i], that._weights[i]+_num_node,_weights[i]);
	}

}

Graph::Graph(Graph&& that)
	:_num_node(that._num_node)
	,_current_node(0)
	,_weights(that._weights)
	,_vertice_mapping(std::move(that._vertice_mapping))
	,_vertice_name(std::move(that._vertice_name))
{
	that._weights=nullptr;
}

Graph& Graph::operator=(Graph that)
{
	std::swap(this->_num_node, that._num_node);
	std::swap(this->_weights, that._weights);
	that._vertice_mapping.swap(this->_vertice_mapping);

	return *this;
}

Graph& Graph::operator=(Graph&& that)
{
	this->_num_node = that._num_node;
	this->_weights = that._weights;
	that._weights = nullptr;
	this->_vertice_mapping = std::move(that._vertice_mapping);

	return *this;
}


Graph::~Graph(void)
{
	for(int i=0; i<_num_node; i++) {
		delete [] _weights[i];
	}
	_num_node = 0;
}

bool Graph::add_node(std::string name)
{
	if (_current_node > _num_node)
		return false;

	if (_vertice_mapping.find(name) != _vertice_mapping.end())
		return false;

	cout << name << ":" << _current_node << endl;
	_vertice_name.push_back(name);
	_vertice_mapping[name]=_current_node++;

	return true;
}

void Graph::add_edge(std::string name1, std::string name2, float weight)
{
	add_node(name1);
	add_node(name2);

	int idx1 = _vertice_mapping[name1];
	int idx2 = _vertice_mapping[name2];
	_weights[idx1][idx2] = weight;
	_weights[idx2][idx1] = weight;

	cout << name1 << " " << name2 << " " << weight << endl;
}

/* get all the nodes from node_idx */
vector<Node> Graph::get_edges(int node_idx)
{
	vector<Node> nodes;

	_ASSERT(node_idx>=0 && node_idx<_num_node);
	for (int i=0; i< _num_node; i++){
		if (_weights[node_idx][i] != HUGE_VAL) {
			Node nd(i, node_idx, _weights[node_idx][i]);
			nodes.push_back(nd);
		}
	}

	return nodes;
}

