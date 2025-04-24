#include "KwizyGraphs.h"

KwizyGraphs::KwizyGraphs()
{
	graphGrid = nullptr;

	deltaY = 0;
	deltaX = 0;
	sizeY = 0;
	sizeX = 0;
}

KwizyGraphs::KwizyGraphs(int sizeY, int sizeX, double delY, double delX)
{
	this->deltaY = delY;
	this->deltaX = delX;

	this->sizeY = sizeY;
	this->sizeX = sizeX;

	graphGrid = new char* [sizeY];
	for (int i = 0; i < sizeY; i++)
		graphGrid[i] = new char[sizeX];

	DrawingVoid();
}

KwizyGraphs::~KwizyGraphs()
{
	for (int i = 0; i < sizeY; i++)
		delete[] graphGrid[i];
	delete[] graphGrid;
}

void KwizyGraphs::SetCenter()
{
	this->zeroIndexY = sizeY / 2;
	this->zeroIndexX = sizeX / 2;

	DrawingAxes();
}

void KwizyGraphs::SetCenter(int indexY, int indexX)
{
	this->zeroIndexY = indexY;
	this->zeroIndexX = indexX;

	DrawingAxes();
}

void KwizyGraphs::SetPoint(double EY, double EX)
{
	int realIndexY = zeroIndexY - static_cast<int>(EY * deltaY);
	int realIndexX = zeroIndexX + static_cast<int>(EX * deltaX);

	if (realIndexY < 0 || realIndexY >= sizeY) return;
	if (realIndexX < 0 || realIndexX >= sizeX) return;

	graphGrid[realIndexY][realIndexX] = '*';
}

void KwizyGraphs::Clear()
{
	DrawingVoid();
	DrawingAxes();
}

void KwizyGraphs::PlotFunction(double(*func)(double), double startX, double endX, double step)
{
	for (double x = startX; x <= endX; x += step)
	{
		double y = func(x);
		SetPoint(y, x);
	}
}

void KwizyGraphs::DrawingGraphs()
{
	for (int i = 0; i < sizeY; i++)
	{
		for (int j = 0; j < sizeX; j++)
			std::cout << graphGrid[i][j];
		std::cout << std::endl;
	}

}

void KwizyGraphs::DrawingVoid()
{
	for (int i = 0; i < sizeY; i++)
		for (int j = 0; j < sizeX; j++)
			graphGrid[i][j] = ' ';
}

void KwizyGraphs::DrawingAxes()
{
	for (int i = 0; i < sizeY; i++)
		graphGrid[i][zeroIndexX] = '|';

	for (int i = 0; i < sizeX; i++)
		graphGrid[zeroIndexY][i] = '-';

	graphGrid[zeroIndexY][zeroIndexX] = '+';
}
