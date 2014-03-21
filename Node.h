//#include "SDL.h"
#include<vector>
#include <iostream>
using namespace std;
#ifndef NODE_H
#define NODE_H
class Node
{
	public:
		Node(int, int, int);
		int getPathNum();
		void setPathNum(int);
		int getY();
		void cascadeNext( vector<vector<Node> > &);
		Node *getNext();
	private:
		int x;
		int y;
		int pathNum;
		Node *next;
		Node *prev;
};

Node::Node( int setx, int sety, int path)
{
	x=setx;
	y=sety;
	pathNum = path;
}

int Node::getY() {return x;}

Node *Node::getNext() {return next;}

void Node::cascadeNext(vector<vector<Node> > &board)
{
	//cout<<getY()<<" compared to "<<board.size()<<endl;
	if(getY()==board.size()-1)
	{
		return;
		
	}
	//cout<<board[x+1][y].getPathNum() <<endl;
	
	if(board[x+1][y].getPathNum() > 0 && this != board[x+1][y].getNext())
	{
		next = &board[x+1][y];
		cout<<"found next at "<<x+1<<", "<<y<<endl;
		board[x+1][y].setPathNum(getPathNum()+1);
		board[x+1][y].cascadeNext(board);
		return;
	}
	if(board[x][y-1].getPathNum() > 0 && this != board[x][y-1].getNext())
	{
		next = &board[x][y-1];
		cout<<"found next at "<<x<<", "<<y-1<<endl;
		board[x][y-1].setPathNum(getPathNum()+1);
		board[x][y-1].cascadeNext(board);
		return;
	}
	if(board[x][y+1].getPathNum() > 0 && this != board[x][y+1].getNext())
	{
		next = &board[x][y+1];
		cout<<"found next at "<<x<<", "<<y+1<<endl;
		board[x][y+1].setPathNum(getPathNum()+1);
		board[x][y+1].cascadeNext(board);
		return;
	}
	if(board[x-1][y].getPathNum() > 0 && this != board[x-1][y].getNext())
	{
		next = &board[x-1][y];
		cout<<"found next at "<<x<<", "<<y+1<<endl;
		board[x-1][y].setPathNum(getPathNum()+1);
		board[x-1][y].cascadeNext(board);
		return;
	}
	//cout<<"Error, could not find next node"<<endl;
	return;
}

void Node::setPathNum(int num)
{
	pathNum = num;
}

int Node::getPathNum()	{return pathNum;}

#endif
