#pragma once
#include "Deamon.h"

void Deamon::SetDLocation(Location place)
{
	m_location.col = place.col;
	m_location.row = place.row;
}

Location Deamon::GetStartDLocation() const
{
	return m_StartLocation;
}

void Deamon::Print() const 
{

	std::cout << '&';
}

void Deamon::SetStartDLocation()
{
	m_StartLocation = m_location;
}
// algorithem to deamons
void Deamon::UpdateLocation(const Location Pac, const char ObjectsAround[], const bool Super)
{
	if (!Super)
	{
		if (m_location.col < Pac.col)
		{
			if (ObjectsAround[0] != 'D' && ObjectsAround[0] != '#')
				m_location.col++;
		}
		else if (m_location.col > Pac.col)
		{
			if (ObjectsAround[1] != 'D' && ObjectsAround[1] != '#')
				m_location.col--;
		}
		else if (m_location.row < Pac.row)
		{
			if (ObjectsAround[2] != 'D' && ObjectsAround[2] != '#')
				m_location.row++;
		}
		else if (m_location.row > Pac.row)
		{
			if (ObjectsAround[3] != 'D' && ObjectsAround[3] != '#')
				m_location.row--;
		}
	}
	else
	{
		if (m_location.col > Pac.col)
		{
			if (ObjectsAround[0] != 'D' && ObjectsAround[0] != '#')
				m_location.col++;
		}
		else if (m_location.col < Pac.col)
		{
			if (ObjectsAround[1] != 'D' && ObjectsAround[1] != '#')
				m_location.col--;
		}
		else if (m_location.row > Pac.row)
		{
			if (ObjectsAround[2] != 'D' && ObjectsAround[2] != '#')
				m_location.row++;
		}
		else if (m_location.row < Pac.row)
		{
			if (ObjectsAround[3] != 'D' && ObjectsAround[3] != '#')
				m_location.row--;
		}
	}
}

Location Deamon::GetLocation() const 
{
	return this->m_location;
}

void Deamon::PrintDeamon(const int row) const//int row
{
	Screen::setLocation(m_location);
	std::cout << '&';	
	Location l(row,0);// this row isnt good!!!!!!!!!! check the row!!!!!
	Screen::setLocation(l);
}
