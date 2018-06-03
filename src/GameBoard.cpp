#include"GameBoard.hpp"
#include<iostream>
#include<vector>
#include<climits>   // includes INT_MIN and INT_MAX
#include<algorithm> // includes std::count
#include<cmath>

using namespace std;

GameBoard::GameBoard(const int width, const int height) : width(width), height(height) 
{
	fields = vector<vector<char>>(width, vector<char>(height, noTokenSymbol));
}

void GameBoard::printField()
{
	//TODO
	cout<<"\n----------------\n";
	for(int heading=0;heading<width;heading++)
	{
		cout<<heading<<"  ";
	}
	cout<<"\n----------------";
	for (int i=height-1;i>=0;i--)
	{
		cout<<endl;
		for(int j=0;j<width;j++)
		{
			cout<<fields[j][i]<<"  ";
		}
	}
	cout<<endl;
}

void GameBoard::executeMove(int column, bool maxPlayersTurn)
{
	//TODO
	char symbol;
	if (maxPlayersTurn)
		symbol=maxPlayerSymbol;
	else
		symbol=minPlayerSymbol;

	for (int i=0;i<height;i++)
	{
		if(fields[column][i]==noTokenSymbol)
		{
			fields[column][i]=symbol;
			break;
		}
	}
}

void GameBoard::undoMove(int column)
{
	//TODO
	for (int i=height-1;i>=0;i--)
	{
		if(fields[column][i]!=noTokenSymbol)
		{
			fields[column][i]=noTokenSymbol;
			break;
		}
	}

}


bool GameBoard::isValidMove(int column)
{
	//TODO
	if (column>=width or column<0 or isFieldFull())
		return false;
	else
	{
		if(isColumnFull(column))
			return false;
		else
			return true;
	}
}
bool GameBoard::isColumnFull(int column)
{
	//TODO
	bool full=true;
	for (int i=0;i<height;i++)
	{
		if(fields[column][i]==noTokenSymbol)
		{
			full=false;
			break;
		}
	}
	return full;
}

bool GameBoard::isFieldFull()
{
	//TODO
	bool full=true;
	for (int i=0;i<height;i++)
	{
		for(int j=0;j<width;j++)
		{
			if(fields[j][i]==noTokenSymbol)
			{
				full=false;
				break;
			}
		}
	}
	return full;
}

vector<vector<char>> GameBoard::getAllQuadruplesInField()
{

	vector<vector<char>> allQuadruple;
	vector<char> quad;

	for(int i=0; i<width;i++)
	{

		for(int j=0;j<height;j++)
		{

			if(j+3<height) //Checking perpendicularly up
			{
				quad = {fields[i][j],fields[i][j+1],fields[i][j+2],fields[i][j+3]};
				allQuadruple.push_back(quad);
			}
			if(j-3>=0) //Checking perpendicularly down
			{
				quad = {fields[i][j],fields[i][j-1],fields[i][j-2],fields[i][j-3]};
				allQuadruple.push_back(quad);
			}

			if(i+3<width) //Checking horizontally right
			{
				quad = {fields[i][j],fields[i+1][j],fields[i+2][j],fields[i+3][j]};
				allQuadruple.push_back(quad);
			}
			if(i-3>=0) //Checking horizontally left
			{
				quad = {fields[i][j],fields[i-1][j],fields[i-2][j],fields[i-3][j]};
				allQuadruple.push_back(quad);
			}

			if(i+3<width and j+3<height) //checking diagonally towards top right
			{
				quad = {fields[i][j],fields[i+1][j+1],fields[i+2][j+2],fields[i+3][j+3]};
				allQuadruple.push_back(quad);
			}

			if(i+3<width and j-3>=0) //checking diagonally towards bottom right
			{
				quad = {fields[i][j],fields[i+1][j-1],fields[i+2][j-2],fields[i+3][j-3]};
				allQuadruple.push_back(quad);
			}
			if(i-3>=0 and j-3>=0) //checking diagonally towards bottom left
			{
				quad = {fields[i][j],fields[i-1][j-1],fields[i-2][j-2],fields[i-3][j-3]};
				allQuadruple.push_back(quad);
			}

			if(i-3>=0 and j+3<height) //checking diagonally towards top left
			{
				quad = {fields[i][j],fields[i-1][j+1],fields[i-2][j+2],fields[i-3][j+3]};
				allQuadruple.push_back(quad);
			}

		}
	}
	return allQuadruple;

}

int GameBoard::getUtility()
{
	//TODO
	vector<vector<char>> quadruples = getAllQuadruplesInField();
	char symbol=noTokenSymbol;
	int count=0;
	int discontiuous_count=0;
	bool flag=true;
	for (auto quad : quadruples)
	{
		//Checking for any continuous sets of 4 symbols
		if(quad[0]!=noTokenSymbol)
		{
			symbol=quad[0];
			count=1;
			for(int i= 1;i<quad.size();i++)
			{
				if(quad[i]!=symbol)
				{
					count =0;
					symbol=noTokenSymbol;
					break;
				}
				else
				{
					count++;
					if(count==4)
					{
						if (symbol==minPlayerSymbol)
							return INT_MIN;
						else
							return INT_MAX;
					}
				}
			}
		}

	}
	if(count==3)
	{
		if (symbol==minPlayerSymbol)
			return INT_MIN/1.5;
		else
			return INT_MAX/1.5;
	}
	return 0;
	/*
	for (auto quad : quadruples)
	{
		//Checking for any discontinuous sets of 3 symbols
		if(quad[0]!=noTokenSymbol)
		{
			symbol=quad[0];
			discontiuous_count=1;
			for(int i= 1;i<quad.size();i++)
			{
				if(quad[i]==symbol)
				{
					discontiuous_count++;
					if(discontiuous_count==3)
					{
						if (symbol==minPlayerSymbol)
							return INT_MIN/1.5;
						else
							return INT_MAX/1.5;
					}
				}
				else if (quad[i]!=symbol and flag==true)
				{
					discontiuous_count++;
					flag=false;
					continue;
				}
				else
				{
					break;
				}
			}
		}
		else
		{
			if (flag==true)
			{
				discontiuous_count++;
				flag=false;
				continue;
			}
		}
	}*/

}
/*int GameBoard::getUtility()
{
	//TODO
	vector<vector<char>> quadruples = getAllQuadruplesInField();
	char max_symbol=maxPlayerSymbol,min_symbol=minPlayerSymbol;
	int max_count=0,min_count=0,total_max=0,total_min=0;
	for (auto quad : quadruples)
	{
		max_count=0, min_count=0;
		for(int i= 1;i<quad.size();i++)
		{
			if(quad[i]==maxPlayerSymbol)
			{
				max_count++;
				if(max_count==4)
				{
					//cout<<"\nMAX";
					return INT_MAX;
				}
			}

			else if(quad[i]==minPlayerSymbol)
			{
				min_count++;
				if(min_count==4)
				{
					//cout<<"\nMIN";
					return INT_MIN;
				}
			}
			else
				continue;
		}
		if(max_count>=total_max)
		{
			total_max=max_count;
		}
		if(min_count>=total_min)
		{
			total_min=min_count;
		}

	}
	if(total_max>=3)
	{
		//cout<<"\nMAX/1.5";
		return INT_MAX/1.5;
	}
	else if (total_min>=3)
	{
		//cout<<"\nMIN/1.5";
		return INT_MIN/1.5;
	}
	else
	{
		//cout<<"\n0";
		return 0;
	}
}*/
