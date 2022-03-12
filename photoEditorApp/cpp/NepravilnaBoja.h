#pragma once
#include <iostream>
#include <exception>
class NepravilnaBoja :
	public std::exception
{
	const char* what()const override
	{
		return "\nNiste uneli lepo koju boju zelite da obradite\n";
	}
};

