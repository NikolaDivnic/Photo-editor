#pragma once
#include <iostream>
#include <exception>
class NemaSelekcija :
	public std::exception
{
public:
	
	   const char* what()const override
	   {
		   return "Nema selekcije u slici\n";
	   }

};

