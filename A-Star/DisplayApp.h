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
	//�����ڴ�
	void AllocateMemory();
	//��ʼ����ͼ
	void initMap();
	//��ʼ���б����еĸ��Ӷ�����
	void initList();
private:
	Point* begin;
	Point* end;
	int** table;
	struct param** list;
};