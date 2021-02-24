#pragma once
#include <iostream>
#include <string>

const int WIDTH = 40;
const int HEIGHT = 40;

const int NEIGHBOUR = 8;

const int row[NEIGHBOUR] = { -1,1,0,0,-1,-1,1,1 };
const int col[NEIGHBOUR] = { 0,0,-1,1,-1,1,-1,1 };

struct Point
{
	Point(int x, int y) : x(x), y(y) {}
	int x;
	int y;

	Point* Neighbour(int k)
	{
		return new Point(x + row[k], y + col[k]);		
	}

	bool CheckEqual(int inX, int inY)
	{
		return x == inX && y == inY;
	}

	bool CheckEqual(Point* point)
	{
		return x == point->x && y == point->y;
	}

	std::string ToString()
	{		
		std::string ret = "(" + std::to_string(x) + ", " + std::to_string(y) + ")";		
		return ret;
	}
};

//定义每个格子的参数列表
struct param
{
	int f;//最终代价
	int g;//从起点到当前点实际代价
	int h;//当前前往终点预估代价
	Point* pos;	
};


