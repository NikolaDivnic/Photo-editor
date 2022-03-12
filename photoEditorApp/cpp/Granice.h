#pragma once
#include<iostream>
class Granice :
	public std::exception
{
	const char* what()const override
	{
		return "\nUneli ste index izvan granica\n";
	}
};
class NemaSlojeva : public std::exception {
	const char* what()const override
	{
		return "\nNema tog sloja lose ste uneli\n";
	}
};

class NemaOperacije : public std::exception {
	const char* what()const override
	{
		return "\nNema operacije sa tim indeksom\n";
	}
};
