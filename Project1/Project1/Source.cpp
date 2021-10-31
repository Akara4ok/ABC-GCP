#include <iostream>
#include "IOClass.h"
#include "ABC.h"

using namespace std;

int main() 
{
	IOClass io;
	Graph g;
	g = io.read("D:\\tests\\input.txt");
	ABC beeColony(g);
	g = beeColony.coloring(4, 1, 5);
	io.write(g, "D:\\tests\\output.txt");
	return 0;
}