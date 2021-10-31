#pragma once
#include<vector>
#include<iostream>
#include <string>

struct Vertex
{
	int index;
	int color;
	int nectar = 0;
	int numberOfBees = -1;
	std::vector<int> adjVertices;
	Vertex() {}
	friend std::ostream& operator<<(std::ostream& os, Vertex v)
	{
		os << v.index << " " << v.color << " " << v.nectar;
		return os;
	}
};