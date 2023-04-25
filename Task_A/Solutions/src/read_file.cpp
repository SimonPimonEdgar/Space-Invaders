#include "read_file.h"
#include <iostream>

const char* getDefaultDelimitersAndStopChars()
{
  return " \t,.?;<>'\"`~!+-*/@#$%^&(){}[]|=\\:\n\r\t";
}

bool isDelimiterOrStopChar ( char c ) {
	return strchr( getDefaultDelimitersAndStopChars(), c ) != NULL;
}

std::vector<std::string> readTextFromFile( std::string fileName )
{
	FILE * fp = fileName.length() > 0 ? fopen( fileName.c_str(), "r" ) : stdin;

	std::vector<std::string> full_text;
	full_text.push_back("#NEW");

	if (fp == NULL)
	{
		printf("Failed to open file %s\n", fileName.c_str());
	}
	else
	{
		int count = 0;
		char c;
		bool isSpecialChar = false;
		std::string token;
		token.reserve(256);
		while ( ( c = (char) fgetc( fp ) ) != EOF )
		{
			if ( isDelimiterOrStopChar( c ) )
			{
				if ( !isSpecialChar && token.length() >0 )
				{
					full_text.push_back(token);
					if ( c == '.' ) {
						full_text.push_back("#NEW");
					}
					token = "";
					++count;
					isSpecialChar = true;
				}
				else
				{
					isSpecialChar = false;
				}

			}
			else
			{ 
				token += c;
				isSpecialChar = false;
			}
	  	}

		fclose( fp );
	}

	return full_text;
}