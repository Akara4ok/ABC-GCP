#include <iostream>
#include "IOClass.h"
#include "ABC.h"

using namespace std;

int main() 
{
	IOClass io;
	Graph g;
	g = io.read("D:\\tests\\test.txt");
	ABC beeColony(g);
	g = beeColony.coloring(3, 3, 85);
	//g.generate();
	io.write(g, "D:\\tests\\output.txt");
	return 0;
}