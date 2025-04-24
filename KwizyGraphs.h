#pragma once
#include <iostream>

class KwizyGraphs
{
public:
	KwizyGraphs();
	KwizyGraphs(int sizeY, int sizeX, double delY = 1, double delX = 1);
	~KwizyGraphs();

	void SetCenter();
	void SetCenter(int indexY, int indexX);
	void SetPoint(double EY, double EX);
	void Clear();

	void PlotFunction(double (*func)(double), double startX, double endX, double step = 0.1);
	void DrawingGraphs();


private:
	char** graphGrid;
	int zeroIndexY;
	int zeroIndexX;
	double deltaY;
	double deltaX;
	int sizeY;
	int sizeX;

	void DrawingVoid();
	void DrawingAxes();
};