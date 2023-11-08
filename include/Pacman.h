#pragma once
#include <iostream>
#include <Location.h>

class Pacman
{
	public:
		//Pacman()= default;
		char GetAppearance() const;
		bool GetIsSuper() const;
		void SetPLocation(const Location place);
		void SetPStartLocation();
		Location GetPStartLocation() const;
		Location GetLocation() const ;
		void UpdateLocation(const Location);
		void UnSetSuper();
		void SetSuper();


	private:
		bool m_isSuper = false;
		char m_Appearance = 'a';
		char m_SuperAppearance = '@';
		Location m_location;
		Location m_StartLocation;

};