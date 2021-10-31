#pragma once
#include <vector>
#include "Vertex.h"

class Graph
{
	int numberOfVertices;
	int** adjMatrix;
	std::vector<Vertex> vertices;

public:
	Graph() {};
	Graph(int n, int** matrix);
	int getNumberofVertices();
	void setNumberOfVertices(int n);
	int** getAdjMatrix();
	void setAdjMatrix(int** m);
	std::vector<Vertex> getVertices();
	void setVertices(std::vector<Vertex> v);
	void pintGraph();
	void copy(Graph& g);
};