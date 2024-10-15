/*
	PLEASE DO NOT CHANGE FILE NAME!

	write your test case validator!
	this is file validate input files
	if input is valid this program finish normally (return 0) otherwise finish with an error (return 1)

	some useful validator tools in testlib:

		+ inf.readInt
			you can read an integer from input file.

			general form:
				int variable_name = inf.readInt(<lower_bound>, <upper_bound>, "<variable_name>");

			example: 
				int n = inf.readInt(1, 100, "n");
				(read an integer name "n" between 1 to 100 inclusive.)
		
		
		+ inf.readToken
			you can read an string from input file
			(without white-space)

			general form:
				variable_name = inf.readToken();
			
			example:
				string s = inf.readToken();
				inf.readToken("[a-z]{1,7}"); // reads string with lowercase with atmost 7 chars

		
		+ inf.readSpace
			read an space. you can use it to validate there is an space here.
		
			general form / example:
				inf.readSpace();
		
		
		+ inf.readEoln
			read an end of line. you can use it to validate there is an end of line here.

			general form / example:
				inf.readEoln();

		
		+ inf.readEof
			it use to see input file finished.
			
			general form / example:
				inf.readEof()


		+ ensuref
			it use to check a condition (like assert)

			general form:
				ensuref(<boolean condition>, "<massage>");

			example:
				ensuref(a + b == c, "invalid input");

*/

#include "testlib.h"

using namespace std;

int main() 
{
	registerValidation();
	
	return 0;
}
