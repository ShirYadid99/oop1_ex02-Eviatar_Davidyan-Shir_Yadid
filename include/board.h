#pragma once
#include <vector>
#include <string>
#include <fstream>
#include <location.h>

class Board
{
	public :

		void Printboard() const;
		void ReadLevel(std::ifstream &file);
		int DeamonsCounter() const;
		int CookiesCounter() const;
		Location Get_location(char creature);
		void InsertObject(const Location ObjL ,const char apper);
		void DeleteChar(const Location);
		char GetChar(const Location) const;
		void ClearMatrix();
		bool CheckValidPacLocation(const Location ,const Location ,const char ,char&);
		Location GetPlocation(const char) const;
		void ClearBoard();
		int GetRow() const;
		



	private:
		int m_row;
		int m_col;
		std::vector<std::string> m_MatrixVector;

 };
