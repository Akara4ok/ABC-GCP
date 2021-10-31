#pragma once
#include <vector>
#include "Bee.h"
#include "Graph.h"

class ABC
{
	std::vector<Bee> employeds;
	std::vector<Bee> onlookers;
	std::vector<Bee> scouts;
	std::vector<float> p;
	int allColors;
	std::vector<int> usedColors;
	int numberOfVertex;
	bool* visited;
	Graph g;
	int minC;
public:
	ABC(Graph g);
	Graph coloring(int k, int e, int o);
};

