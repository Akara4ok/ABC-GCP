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
