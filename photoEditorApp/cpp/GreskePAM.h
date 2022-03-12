#pragma once
#include <iostream>

class GreskePAMOtvaranje :
	public std::exception
{
	const char* what()const override
	{
		return "\nGreska! Prilikom otvaranje fajla.PAM \n";
	}
};
class GreskaPAMformat :
	public std::exception
{
	const char* what()const override
	{
		return "\nNije dobar format ,treba da bude PAM \n";
	}
};
class NijePodrezanTajPamFormat :
	public std::exception
{
	const char* what()const override
	{
		return "\n Nije podrzan taj pam format mora da bude RGB ili RGB_ALPHA \n";
	}
};

class GreskePAmCuvanje :
	public std::exception
{
	const char* what()const override
	{
		return "\nGreska! Prilikom cuvanja fajla.Pam \n";
	}
};