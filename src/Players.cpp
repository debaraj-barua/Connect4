#include<Players.hpp>
#include<climits>
#include<algorithm> //includes std::max
#include<string>
#include<iostream>
#include <math.h>

using namespace std;

int ComputerPlayer::makeMove()
{
	//TODO
	int column, alpha, beta;
	pair <int,int> minimaxValue,aplhabetaValue;
	float column_value;
	GameBoard current_board=*board;
	if (pruningEnabled)
	{
		aplhabetaValue=getAlphaBetaValue(0, isMaxPlayer, alpha, beta);
		column=aplhabetaValue.second;
	}
	else
	{
		minimaxValue=getMinimaxValue(0, isMaxPlayer);
		column= minimaxValue.second;
	}
	board->executeMove(column, isMaxPlayer);
	return column;
}


pair <int,int> ComputerPlayer::getMinimaxValue(int depth, bool isMaxPlayer)
{
	//TODO

	int max=INT_MIN, min=INT_MAX, column=-1;
	depth++;
	if(checkTerminalState(*board))
	{
		return make_pair(board->getUtility(),-1);
	}
	else
	{
		if(depth>=maxDepth)
		{
			return make_pair(board->getUtility(),-1);
		}
		for(int i=0;i<board->getWidth();i++)
		{
			pair <int,int> minmaxValue;
			if(board->isValidMove(i))
			{
				board->executeMove(i, isMaxPlayer);
				if (isMaxPlayer)
				{
					minmaxValue=getMinimaxValue(depth,false);
					int check_max=minmaxValue.first;
					if(check_max>max)
					{
						max=check_max;
						column=i;
					}
				}
				else
				{
					minmaxValue=getMinimaxValue(depth,true);
					int check_min=minmaxValue.first;
					if(check_min<min)
					{
						min=check_min;
						column=i;
					}
				}
				board->undoMove(i);
			}

		}
		if (isMaxPlayer)
		{
			return make_pair(max,column);
		}

		else
		{
			return make_pair(min,column);
		}

	}
}

pair <int,int> ComputerPlayer::getAlphaBetaValue(int depth, bool isMaxPlayer, int alpha, int beta)
{
	//TODO
	int max=INT_MIN, min=INT_MAX, column=-1;
		depth++;
		if(checkTerminalState(*board))
		{
			return make_pair(board->getUtility(),-1);
		}
		else
		{
			if(depth>=maxDepth)
			{
				return make_pair(board->getUtility(),-1);
			}
			for(int i=0;i<board->getWidth();i++)
			{
				pair <int,int> minmaxValue;
				if(board->isValidMove(i))
				{
					board->executeMove(i, isMaxPlayer);
					if (isMaxPlayer)
					{
						minmaxValue=getAlphaBetaValue(depth,false,alpha,beta);
						int check_max=minmaxValue.first;
						if(check_max>max)
						{
							max=check_max;
							column=i;
						}
						board->undoMove(i);
						if (max>beta) return make_pair(max,column);
						if(max>alpha) alpha=max;
						//if (alpha <= beta) return make_pair(max,column);
					}
					else
					{
						minmaxValue=getAlphaBetaValue(depth,true,alpha,beta);
						int check_min=minmaxValue.first;
						if(check_min<min)
						{
							min=check_min;
							column=i;
						}

						board->undoMove(i);
						if (min<alpha) return make_pair(min,column);
						if(min<beta) beta=min;
						//if (alpha >= beta) return make_pair(min,column);
					}

				}

			}
			if (isMaxPlayer)
			{
				return make_pair(max,column);
			}

			else
			{
				return make_pair(min,column);
			}

		}
}

int HumanPlayer::makeMove()
{
	//TODO
	int column;
	bool cont=true;
	while(cont)
	{
		cout<<"\nEnter Move:";
		cin>>column;
		if(board->isValidMove(column))
		{
			board->executeMove(column, isMaxPlayer);
			cont=false;
		}
		else
			cout<<"\n Invalid Move. Try Again.\n";
	}
	return column;

}

bool ComputerPlayer::checkTerminalState(GameBoard current_board)
{
	int current_utility=current_board.getUtility();
	if (current_utility == INT_MAX)
		return true;
	else
		return false;

}
