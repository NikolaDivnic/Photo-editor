#pragma once
#include <iostream>
class GreskeMojCuvanje :
	public std::exception
{
	const char* what()const override
	{
		return "\nGreska! Prilikom cuvanja  mog fajla. \n";
	}
};
class GreskaMojOtvaranje :
	public std::exception
{
	const char* what()const override
	{
		return "\nGreska! Prilikom otvaranja  mog fajla. \n";
	}
};

