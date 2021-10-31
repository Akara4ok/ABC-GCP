#pragma once
#include "Graph.h"
#include <string>
#include <map>

class IOClass
{
public:
	IOClass() {};
	Graph read(std::string name);
	void write(Graph g, std::string name);
};

