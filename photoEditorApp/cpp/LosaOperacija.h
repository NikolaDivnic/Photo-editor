#pragma once
#include<iostream>
class LosaOperacija :
	public std::exception
{
	const char* what()const override
	{
		return "\nLos unos u konstruktoru\n";
	}
};

