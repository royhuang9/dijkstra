#pragma once
#include <unordered_map>
#include <set>
#include <vector>
#include <queue>
#include <stack>

#include "node.h"
#include "Graph.h"

struct ComparisonClass {
	bool operator() (Node &n1, Node &n2) {
		return n1._weight > n2._weight;
	}
};

class ShortestPath
{
public:
	ShortestPath(void);
	~ShortestPath(void);
	float dijkstra(Graph &g, const std::string  &start, const std::string &end);
	std::vector<std::string> path();

private:
	std::priority_queue<Node, std::vector<Node>, ComparisonClass> _open_queue;
	std::unordered_map<int, Node> _close_nodes;
	std::stack<std::string> _path;
};

/*
���˼·��
һ�����ж��������֣�����һ������
���������·����Ҳ��֪�������ߵ�����·��
*/
