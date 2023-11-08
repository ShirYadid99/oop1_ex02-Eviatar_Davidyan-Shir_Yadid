#pragma once
#include <Location.h>
#include <iostream>
#include <io.h>
class Deamon
{
	public:
		void Print() const;
		void SetDLocation(const Location place);
		Location GetStartDLocation() const;
		void SetStartDLocation();
		void UpdateLocation(const Location, const char[], const bool);
		Location GetLocation() const ;
		void PrintDeamon(const int) const ;

	private:
		Location m_location;
		Location m_StartLocation;

};