#include "IOClass.h"
#include <fstream>
#include <vector>
#include <string>

Graph IOClass::read(std::string name)
{
	std::ifstream fin(name);
	int n;
	fin >> n;
	int** matrix = new int*[n];
	for (int i = 0; i < n; i++)
	{
		matrix[i] = new int[n];
		for (int j = 0; j < n; j++)
		{
			fin >> matrix[i][j];
		}
	}
	fin.close();
	return Graph(n, matrix);
}

void IOClass::write(Graph g, std::string name)
{
	std::ofstream fout(name);
	int** matrix = g.getAdjMatrix();
	for (int i = 0; i < g.getNumberofVertices(); i++)
	{
		for (int j = 0; j < g.getNumberofVertices(); j++)
		{
			fout << matrix[i][j] << " ";
		}
		fout << "\n";
	}
	fout << "\n";

	std::vector<Vertex> v = g.getVertices();
	for (int i = 0; i < g.getNumberofVertices(); i++)
	{
		fout << v[i] << "\n";
	}
	fout.close();
}