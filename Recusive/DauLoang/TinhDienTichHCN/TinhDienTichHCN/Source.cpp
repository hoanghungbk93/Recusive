#include<iostream>
#include<vector>
using namespace std;


struct position
{
	int x;
	int y;
};

typedef position Position;
bool positionCompare(Position one, Position two)
{
	bool ret = false;

	if(one.x == two.x && abs(one.y - two.y) == 1 || one.y == two.y && abs(one.x - two.x) == 1 )
	{
		ret = true;
	}

	return ret;
}
bool ignoreElement(vector<vector<Position>>group, Position point)
{
	bool ret = false;
	for(int i = 0; i < group.size(); i++)
	{
		for(auto &element : group[i])
		{
			if(true == positionCompare(element, point))
			{
				ret = true;
			}
		}
	}
	return ret;
}
void findVt(vector<Position > vt, vector<bool > followVt, int index, vector<vector<Position>>group, vector<Position> tempVector)
{
	for(int i = index; i < vt.size(); i++)
	{
		if(false == followVt[i])
		{
			followVt[i] = true;
			for(int i = 0; i < vt.size(); i++)
			{
				if(index == i)
				{
					continue;
				}
				if(true == positionCompare(vt[index], vt[i]))
				{
					tempVector.push_back(vt[i]);
					findVt(vt, followVt, i, group, tempVector);
				}
			}
		}
		if(tempVector.size() != 0)
		{
			group.push_back(tempVector);
		}
		tempVector.clear();
	}
}
int main()
{
	int a[7][10] = {
		{1,1,1,1,0,0,1,1,1,0},
		{1,1,1,1,0,0,1,1,1,0},
		{1,1,1,1,0,0,1,1,1,0},
		{1,1,1,1,0,0,1,1,1,0},
		{1,1,1,1,0,0,1,1,1,0},
		{1,1,1,1,0,0,1,1,1,0},
		{1,1,1,1,0,0,1,1,1,0}
	};
	vector<Position > vt;
	for(int i = 0; i < 7; i++)
	{
		for(int j =0; j < 10; j++)
		{
			if(1 == a[i][j])
			{
				Position temp;
				temp.x = i;
				temp.y = j;
				vt.push_back(temp);
			}
		}
	}
	vector<bool> followVt;
	for(int i =0; i < vt.size(); i++)
	{
		followVt.push_back(false);
	}
	//make list
	int elementNumber = 0;
	//make group vetor
	vector<vector<Position>>group; 
	vector<Position> tempVector;
	findVt(vt, followVt, 0, group, tempVector);
	cout<<"HungHC";
}