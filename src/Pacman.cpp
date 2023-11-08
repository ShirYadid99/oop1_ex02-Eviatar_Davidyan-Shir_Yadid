#include <Pacman.h>



//return the pacman to its intial location on the board 
void Pacman::SetPStartLocation()
{
	m_StartLocation = m_location;
}

//return the intial loction of pacman - case we are dead
Location Pacman::GetPStartLocation() const 
{
	return m_StartLocation;
}

void Pacman::SetPLocation(const Location place)
{
	m_location.col = place.col;
	m_location.row = place.row;
}

//returns the apperance according to the state
char Pacman::GetAppearance() const  
{
	if (m_isSuper)
		return m_SuperAppearance;
	return m_Appearance;
}

//return the bool od the state of pacman 
bool Pacman::GetIsSuper() const
{
	return m_isSuper;
}




Location Pacman::GetLocation() const 
{
	return m_location;
}

//update the new level 
void Pacman::UpdateLocation(Location direction)
{
	m_location.col += direction.col;
	m_location.row += direction.row;
}

//if the bool is super - unsuper him 
void Pacman::UnSetSuper()
{
	m_isSuper = false;
}

void Pacman::SetSuper()
{
	m_isSuper = true;
}
