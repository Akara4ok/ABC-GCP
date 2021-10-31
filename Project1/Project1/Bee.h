#pragma once

enum Type {
	employed,
	onlooker,
	scout
};

struct Bee
{
	Type type;
	int position;
};