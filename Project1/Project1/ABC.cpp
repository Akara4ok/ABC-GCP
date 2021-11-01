#include "ABC.h"
#include <ctime>

ABC::ABC(Graph g)
{
	this->g = g;
	srand(time(NULL));
	numberOfVertex = g.getNumberofVertices();
	allColors = 100;
}

Graph ABC::coloring(int k, int e, int o)
{
	k = k - 1;
	int sum = 0;
	int** m = g.getAdjMatrix();
	int coloredVertices;
	minC = allColors;
	int cv = 0;
	int t = 0;
	Graph emptyGraph;
	g.copy(emptyGraph);
	Graph result;
	while (minC > k && t < 20 )
	{
		t++;
		employeds.clear();
		onlookers.clear();
		for (int i = 0; i < e; i++)
		{
			Bee b;
			b.type = employed;
			b.position = rand() % numberOfVertex;
			employeds.push_back(b);
		}
		for (int i = 0; i < o; i++)
		{
			Bee b;
			b.type = onlooker;
			b.position = -1;
			onlookers.push_back(b);
		}
		std::vector<Vertex> vertices = g.getVertices();
		std::vector<int> index;
		for (int i = 0; i < numberOfVertex; i++)
			index.push_back(i);
		cv = 0;
		int max = 0;
		while (!onlookers.empty())
		{
			int i = 0;
			coloredVertices = 0;
			int employedSize = 0;


			sum = 0;
			std::vector<int> index1 = index;
			int q = employeds.size();
			for (int i = 0; i < q; i++)
			{
				if (index1.size() != 0)
				{
					int l = rand() % index1.size();
					int k = index1[l];
					index1.erase(index1.begin() + l);
					employeds[i].position = k;
					sum = sum + vertices[k].nectar;
				}
				else
				{
					employeds.pop_back();
				}
			}
			p.clear();
			bool fl = true;
			for (int i = 0; i < employeds.size(); i++)
			{
				if (vertices[employeds[i].position].adjVertices.size() == 0)
				{
					vertices[employeds[i].position].color = 0;
				}
				p.push_back((float)vertices[employeds[i].position].nectar / sum);
				if (p.back() > 0.000001)
					fl = false;
			}
			if (fl)
				break;
			employedSize = p.size();
			while (i < onlookers.size() && coloredVertices != employedSize)
			{
				float pt;
				while (onlookers[i].position == -1)
				{
					pt = ((float)(rand() % 10000 + 1) / 10000);
					for (int j = 0; j < p.size(); j++)
					{
						if (p[j] >= pt)
						{
							onlookers[i].position = employeds[j].position;
							break;
						}
					}
				}
				int n = 0;
				int currentVertex = 0;
				for (int j = 0; j < vertices[onlookers[i].position].adjVertices.size(); j++)
				{
					if (vertices[vertices[onlookers[i].position].adjVertices[j]].color == -1)
					{
						currentVertex = j;
						break;
					}
				}
				int c = 0;
				bool isCorrect = false;
				while (!isCorrect)
				{
					isCorrect = true;
					vertices[vertices[onlookers[i].position].adjVertices[currentVertex]].color = c;
					for (int j = 0; j < vertices[vertices[onlookers[i].position].adjVertices[currentVertex]].adjVertices.size(); j++)
					{
						if (vertices[vertices[onlookers[i].position].adjVertices[currentVertex]].color == vertices[vertices[vertices[onlookers[i].position].adjVertices[currentVertex]].adjVertices[j]].color)
						{
							isCorrect = false;
							break;
						}
					}
					if (c > max)
						max = c;
					c++;
				}
				//vertices[onlookers[i].position].nectar--;
				bool isAllColored = true;
				for (int j = 0; j < vertices[onlookers[i].position].adjVertices.size(); j++)
				{
					if (vertices[vertices[onlookers[i].position].adjVertices[j]].color == -1)
					{
						isAllColored = false;
						break;
					}
				}
				if (isAllColored)
				{
					coloredVertices++;
					for (int j = 0; j < employeds.size(); j++)
					{
						if (onlookers[i].position == employeds[j].position)
						{
							p[j] = 0;
							break;
						}
					}
					isCorrect = false;
					c = 0;
					if (vertices[onlookers[i].position].color == -1)
					{
						while (!isCorrect)
						{
							isCorrect = true;
							vertices[onlookers[i].position].color = c;
							for (int j = 0; j < vertices[onlookers[i].position].adjVertices.size(); j++)
							{
								if (vertices[onlookers[i].position].color == vertices[vertices[onlookers[i].position].adjVertices[j]].color)
								{
									isCorrect = false;
									break;
								}
							}
							if (c > max)
								max = c;
							c++;
						}
					}
					//index.erase(find(index.begin(), index.end(), onlookers[i].position));
					int pos = onlookers[i].position;
					for (int j = 0; j <= i; j++)
					{
						if (onlookers[j].position == onlookers[i].position)
						{
							onlookers[j].position = -1;
						}
					}

					Bee b = onlookers[i];
					b.type = employed;
					employeds.push_back(b);
					onlookers.erase(onlookers.begin() + i);
					vertices[pos].nectar = 0;
					i--;
				}
				i++;
				for (int j = 0; j < onlookers.size(); j++)
				{
					onlookers[j].position = -1;
				}
			}
			bool isColored = true;
			for (int j = 0; j < vertices.size(); j++)
			{
				if (vertices[j].color == -1)
					isColored = false;
				if (vertices[j].color != -1 && find(index.begin(), index.end(), j) != index.end())
					index.erase(find(index.begin(), index.end(), j));
			}
			if (isColored)
				break;
		}
		for (int j = 0; j < vertices.size(); j++)
		{
			if (vertices[j].color != -1)
				cv++;
		}
		if (max < minC && cv == numberOfVertex)
		{
			minC = max;
			g.setVertices(vertices);
			g.copy(result);
		}
		emptyGraph.copy(g);
	}
	result.copy(g);
	return g;
}
