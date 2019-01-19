#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
struct position
{
	int x;
	int y;
};

typedef struct position Position;

void findAllPoint(int a[][10], vector<Position> &allPoint)
{
	for(int i = 0; i< 7; i++)
	{
		for(int j = 0; j < 10; j++)
		{
			if(1 == a[i][j])
			{
				Position point;
				point.x = i;
				point.y = j;
				allPoint.push_back(point);
			}
		}
	}
}
void makeVisitedVector(vector<Position> allPoint, vector<bool> &visitedVector)
{
	for(int i = 0; i < allPoint.size(); ++i)
	{
		visitedVector.push_back(false);
	}
}

bool isNearPoint(Position point1, Position point2 )
{
	int ret = false;
	if((point1.x == point2.x && (1 == abs(point1.y - point2.y))) || (point1.y == point2.y && (1 == abs(point1.x - point2.x))))
	{
		ret = true;
	}
	return ret;
}

bool existElement(vector<Position> tempVtPoint, Position point)
{
	bool ret = false;
	for(int i = 0; i< tempVtPoint.size(); i++)
	{
		if(tempVtPoint[i].x == point.x && tempVtPoint[i].y == point.y)
		{
			ret = true;
		}
	}
	return ret;
}
void findAllNearPoint(vector<Position> allPoint, vector<vector<Position>> &group, int index, vector<bool> &visitedVector, vector<Position> &tempVtPoint)
{

	if(false == existElement(tempVtPoint, allPoint[index]))
	{
		tempVtPoint.push_back(allPoint[index]);
		visitedVector[index] = true;
	}
	for(int i = 0; i < allPoint.size(); i++)
	{	
		if(false == visitedVector[i])
		{
			if(0 == tempVtPoint.size() )
			{
				tempVtPoint.push_back(allPoint[i]);
				visitedVector[i] = true;
				findAllNearPoint(allPoint, group, i, visitedVector, tempVtPoint);
			}
			else if(isNearPoint(allPoint[i], allPoint[index]))
			{	
				visitedVector[i] = true;			
				tempVtPoint.push_back(allPoint[i]);
				findAllNearPoint(allPoint, group, i, visitedVector, tempVtPoint);
				if(0 != tempVtPoint.size())
				{
					group.push_back(tempVtPoint);
					tempVtPoint.clear();
				}
			}
		}
	}	
}

vector<Position> maxPlace(vector<vector<Position>> group)
{
	int imax = -1;
	vector<Position> retVt;
	if(0 < group[0].size())
	{	
		int maxSize = group[0].size();
		imax = 0;
		for(int i = 1; i< group.size(); i++)
		{
			int temp = group[i].size();
			if(temp > maxSize)
			{
				maxSize = temp;
				imax = i;
			}
		}
	}
	if(-1 != imax)
	{
		retVt = group[imax];
	}
	return retVt;
}
int calcultateCircuit(vector<Position> placeMaxi)
{
	int circuit = 0;
	circuit =  placeMaxi.size();
	return circuit;
}

int numberOneBeside(vector<Position> placeMaxi, Position point)
{
	int ret = 0;
	for(int i = 0; i < placeMaxi.size(); i++)
	{
		if(true == isNearPoint(point, placeMaxi[i]))
		{
			ret++;
		}
	}
	return ret;
}
int calcultateStretch(vector<Position> placeMaxi)
{
	int circuit = 0;
	for(int i = 0; i< placeMaxi.size(); i++)
	{
		circuit += 4 - numberOneBeside(placeMaxi, placeMaxi[i]);
	}
	return circuit;
}
int main()
{
	int a[7][10] = {
		{1,1,1,1,0,0,0,0,1,1},
		{1,1,1,1,0,0,0,0,1,1},
		{1,1,1,1,0,0,0,0,1,1},
		{1,1,1,1,0,1,0,0,1,1},
		{1,1,1,1,0,0,0,0,1,1},
		{1,1,1,1,0,0,0,0,1,1},
		{1,1,1,1,0,0,0,0,1,1}
	};
	//alloint = {0,0}{0.1}...
	vector<Position> allPoint;
	vector<Position> placeMaxi;
	vector<vector<Position>> group;
	findAllPoint(a, allPoint);
	cout<< "size of vector : "<< allPoint.size()<< endl;
	vector<bool> visitedVector;
	makeVisitedVector(allPoint, visitedVector);
	vector<Position> tempVtPoint;
	findAllNearPoint(allPoint, group, 0, visitedVector, tempVtPoint);
	if(0 < group.size())
	{
		placeMaxi = maxPlace(group);
		int circuit = calcultateStretch(placeMaxi);
		cout << "Circuit is  : " << circuit<< endl;
	}	
	system("pause");
	return 0;
}
