#pragma once
#include <iostream>

class GreskeBmpOtvaranje :
	public std::exception
{
	const char* what()const override
	{
		return "\nGreska! Prilikom otvaranje fajla. \n";
	}
};
class GreskeBmpFormat :
	public std::exception
{
	const char* what()const override
	{
		return "\nNije dobar format ,treba da bude bmp \n";
	}
};
class GreskeBmpKompresija :
	public std::exception
{
	const char* what()const override
	{
		return "\nIma kompresije prilikom citanje bmp fajla \n";
	}
};
class GreskeBmpBoje :
	public std::exception
{
	const char* what()const override
	{
		return "\nPrilikom citanja neke boje ne valjaju \n";
	}
};
class GreskeBmpNijeSlika :
	public std::exception
{
	const char* what()const override
	{
		return "\nNije bmp slika\n";
	}
};
class GreskeBmpCuvanje :
	public std::exception
{
	const char* what()const override
	{
		return "\nGreska! Prilikom cuvanja fajla. \n";
	}
};