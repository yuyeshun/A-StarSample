#pragma once

struct Point;

class DisplayApp
{
public:
	DisplayApp();
public:
	void Init();

	void RunAStar();	
private:
	//分配内存
	void AllocateMemory();
	//初始化地图
	void initMap();
	//初始化列表，所有的格子都开放
	void initList();
private:
	Point* begin;
	Point* end;
	int** table;
	struct param** list;
};