#include "Graph.h"
#include <iostream>
#include <math.h>
#include <ctime>

Graph::Graph(int n, int** matrix)
{
	srand(time(NULL));
	numberOfVertices = n;
	adjMatrix = matrix;
	for (int i = 0; i < numberOfVertices; i++)
	{
		Vertex v;
		v.index = i;
		v.color = -1;
		for (int j = 0; j < numberOfVertices; j++)
		{
			if (adjMatrix[i][j])
			{
				v.adjVertices.push_back(j);
				v.nectar++;
			}
		}
		vertices.push_back(v);
	}
}

int Graph::getNumberofVertices()
{
	return numberOfVertices;
}

void Graph::setNumberOfVertices(int n)
{
	numberOfVertices = n;
}

int** Graph::getAdjMatrix()
{
	return adjMatrix;
}

void Graph::setAdjMatrix(int** m)
{
	adjMatrix = m;
}

std::vector<Vertex> Graph::getVertices()
{
	return vertices;
}

void Graph::pintGraph()
{
	for (int i = 0; i < numberOfVertices; i++)
	{
		for (int j = 0; j < numberOfVertices; j++)
		{
			std::cout << adjMatrix[i][j];
		}
	}
	for (int i = 0; i < numberOfVertices; i++)
		std::cout << vertices[i];
}

void Graph::copy(Graph& g)
{
	int** m = new int* [numberOfVertices];
	for (int i = 0; i < numberOfVertices; i++)
	{
		m[i] = new int[numberOfVertices];
		for (int j = 0; j < numberOfVertices; j++)
		{
			m[i][j] = adjMatrix[i][j];
		}
	}
	g.setNumberOfVertices(numberOfVertices);
	g.setAdjMatrix(m);
	g.setVertices(vertices);
}

void Graph::setVertices(std::vector<Vertex> v)
{
	vertices = v;
}


void Graph::generate()
{
	numberOfVertices = 250;
	adjMatrix = new int* [numberOfVertices];
	std::vector<int> example;
	for (int i = 0; i < numberOfVertices; i++)
	{
		adjMatrix[i] = new int[numberOfVertices];
		for (int j = 0; j < numberOfVertices; j++)
		{
			adjMatrix[i][j] = 0;
		}
		example.push_back(i);
	}
	example.pop_back();
	example.pop_back();
	example.pop_back();
	for (int i = 0; i < numberOfVertices - 3; i++)
	{
		Vertex v;
		v.index = i;
		v.color = -1;
		for (int j = 0; j < numberOfVertices; j++)
		{
			if (adjMatrix[i][j])
			{
				v.adjVertices.push_back(j);
				v.nectar++;
			}
		}
		if (i != numberOfVertices - 4)
			v.nectar = std::min((rand() % 24 + 2), numberOfVertices - 2 - i);
		else
			v.nectar = 1;
		std::vector<int> index = example;
		index.erase(index.begin(), index.begin() + v.adjVertices.size());
		int degree = v.nectar;
		int h = v.adjVertices.size();
		while (h < v.nectar)
		{
			if (!index.empty())
			{
				int l = rand() % index.size();
				int k = index[l];
				index.erase(index.begin(), index.begin() + l + 1);
				int count = 0;
				for (int m = 0; m < numberOfVertices; m++)
				{
					if (adjMatrix[k][m])
						count++;
				}
				if (count < 25)
				{
					v.adjVertices.push_back(k);
					adjMatrix[i][k] = 1;
					adjMatrix[k][i] = 1;
					h++;
				}
			}
			else
			{
				break;
			}
		}
		vertices.push_back(v);
	}

	vertices.back().nectar++;

	Vertex v1;
	v1.nectar = 3;
	v1.color = -1;
	v1.index = numberOfVertices - 3;
	v1.adjVertices.push_back(numberOfVertices - 2);
	v1.adjVertices.push_back(numberOfVertices - 1);
	vertices.push_back(v1);
	Vertex v2;
	v2.nectar = 2;
	v2.color = -1;
	v2.index = numberOfVertices - 2;
	v2.adjVertices.push_back(numberOfVertices - 3);
	v2.adjVertices.push_back(numberOfVertices - 1);
	vertices.push_back(v2);
	Vertex v3;
	v3.nectar = 2;
	v3.color = -1;
	v3.index = numberOfVertices - 1;
	v3.adjVertices.push_back(numberOfVertices - 3);
	v3.adjVertices.push_back(numberOfVertices - 2);
	vertices.push_back(v3);

	adjMatrix[numberOfVertices - 3][numberOfVertices - 2] = 1;
	adjMatrix[numberOfVertices - 3][numberOfVertices - 1] = 1;
	adjMatrix[numberOfVertices - 2][numberOfVertices - 3] = 1;
	adjMatrix[numberOfVertices - 2][numberOfVertices - 1] = 1;
	adjMatrix[numberOfVertices - 1][numberOfVertices - 3] = 1;
	adjMatrix[numberOfVertices - 1][numberOfVertices - 2] = 1;
	adjMatrix[numberOfVertices - 4][numberOfVertices - 3] = 1;
	adjMatrix[numberOfVertices - 3][numberOfVertices - 4] = 1;

	for (int i = 0; i < numberOfVertices; i++)
	{
		adjMatrix[i][i] = 0;
	}
}