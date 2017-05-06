#pragma once

class Node {
public:
	int _node_idx;
	int _node_up;
	float _weight;
	
	Node() {}

	Node(int idx, int up, float w):_node_idx(idx),_node_up(up),_weight(w)
	{}

	~Node() {}
};