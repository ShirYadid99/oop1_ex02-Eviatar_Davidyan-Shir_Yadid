#pragma once
#include"board.h"
#include"Pacman.h"
#include <iostream>

//This function print to board one line by one 
void Board::Printboard() const
{
	//std::cout << m_row << ' ' << m_col << std::endl;
	for (int i = 0; i < m_MatrixVector.size(); i++)
	{
		std::cout << m_MatrixVector[i] << '\n';
	}
}
//This function read the board from the file
void Board::ReadLevel( std::ifstream& file)
{
	file >> m_row >> m_col;
	file.get();  // for \n
	auto line = std::string();
	for (int i = m_row; i > 0; i--)
	{
		std::getline(file, line);
		m_MatrixVector.push_back(line);
	}
}

//This function search for a char in the board and return its location 
Location Board::Get_location(char creature)
{
	for (int i = 0; i < m_MatrixVector.size(); i++)
	{
		for (int j = 0; j < m_MatrixVector[i].size(); j++)
		{
			if (m_MatrixVector[i][j] == creature)
			{
				m_MatrixVector[i][j] = ' ';
				Location v(i, j);
				return v;
			}
		}
	}
	Location v2(0, 0);
	return v2;
}


Location Board::GetPlocation(const char creature) const
{
	for (int i = 0; i < m_MatrixVector.size(); i++)
	{
		for (int j = 0; j < m_MatrixVector[i].size(); j++)
		{
			if (m_MatrixVector[i][j] == creature)
			{
				Location v(i, j);
				return v;
			}
		}
	}
	Location v2(0, 0);
	return v2;
}


//This func count how many demons there are
int Board::DeamonsCounter()const 
{
	int counter = 0;
	for (int i = 0; i < m_MatrixVector.size(); i++)
	{
		for (int j = 0; j < m_MatrixVector[i].size(); j++)
		{
			if (m_MatrixVector[i][j] == '&')
			{
				counter++;
			}
		}
	}
	return counter;
}

//This func counts the number of cookies
int Board::CookiesCounter() const 
{
	int counter = 0;
	for (int i = 0; i < m_MatrixVector.size(); i++)
	{
		for (int j = 0; j < m_MatrixVector[i].size(); j++)
		{
			if (m_MatrixVector[i][j] == '*')
			{
				counter++;
			}
		}
	}
	return counter;
}

//This function insert a char to the board
void Board::InsertObject(Location ObjL, char apper)
{
	if (apper == '*')
	{
		m_MatrixVector[ObjL.row][ObjL.col] = ' ';
	}
	else
	{
		m_MatrixVector[ObjL.row][ObjL.col] = apper;

	}
}

//This func deletes a char from the board
void Board::DeleteChar(Location l)
{
	if(m_MatrixVector[l.row][l.col] != '#')
		m_MatrixVector[l.row][l.col] = ' ';
}

char Board::GetChar(const Location l) const 
{
	return m_MatrixVector[l.row][l.col];
}

void Board::ClearMatrix()
{
	m_MatrixVector.clear();
}

//checks if the move is valid by the board
bool Board::CheckValidPacLocation(Location direction, Location pac, char appear ,char& objectToBe)
{
	pac.col += direction.col;
	pac.row += direction.row;

	objectToBe = m_MatrixVector[pac.row][pac.row];

	if (m_MatrixVector[pac.row][pac.col] == '#')
		return false;
	else if (m_MatrixVector[pac.row][pac.col] == 'D' && appear == 'a')
		return false;
	return true;
}

//clears the board from the deamons
void Board::ClearBoard()
{
	
	for (int i = 0; i < m_MatrixVector.size(); i++)
	{
		for (int j = 0; j < m_MatrixVector[i].size(); j++)
		{
			if (m_MatrixVector[i][j] == '&')
			{
				m_MatrixVector[i][j] = ' ';
				
			}
		}
	}
	
}

int Board::GetRow() const
{
	return m_row;
}
