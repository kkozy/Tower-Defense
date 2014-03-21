//#include "SDL.h"
#include "Node.h"
#include <string>
#include<iostream>
#include<fstream>
#include<cmath>
#include<cstdlib>
#include<vector>

using namespace std;
int main(int argc, char* args[])
{
	const int TILE_SIZE = 32;
	ifstream myfile("paths.txt");
	if(!myfile)
	{
		cout<<"File not found"<<endl;
		return 0;
	}
	vector<int> readin;
	vector<vector<Node > > paths;
	while(!myfile.eof())
	{
		int read;
		myfile>>read;
		readin.push_back(read);
	}
	int rowsize = sqrt(readin.size());
	for(int x = 0; x<rowsize; x++)
	{
		vector<Node> curRow;
		for(int y = 0; y<rowsize; y++)
		{
			Node a = Node(x, y, readin[x*rowsize+y]);
			curRow.push_back(a);
		}
		paths.push_back(curRow);
	}
	for(int y = 0; y<rowsize; y++)
	{
		if(paths[0][y].getPathNum()!=0)
			paths[0][y].cascadeNext(paths);
	}
	
	for(int x = 0; x<rowsize; x++)
	{
		for(int y = 0; y<rowsize; y++)
		{
			cout<<paths[x][y].getPathNum()<<" ";
		}
		cout<<endl;
	}
		
}
