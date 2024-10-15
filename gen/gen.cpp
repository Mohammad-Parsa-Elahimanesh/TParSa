/*
	YOU CAN MAKE SO MANY FILES LIKE THAT!

    write your input generator here!
    you can pass argument as input.
    you should print standard output (example: cout) to make your input file
	your random seeds come from argument line in "data" file.

	some useful generator tools in testlib:
		+ rnd.next
			use to generate a random number

			general form:
				int variable_name = rnd.next(<lower_bound>, <upper_bound>);

			example:
				int dice = rnd.next(1, 6);
				(make an integer between 1 to 6 inclusive uniformly.)

		+ shuffle
			use to shuffle an array or vector

			general form:
				shuffle(<starting_pointer>, <ending_pointer>);

			example:
				shuffle(a, a + n);
				shuffle(v.begin(), v.end())

*/

#include <bits/stdc++.h>
#include "testlib.h"

using namespace std;

int main(int argc, char *argv[]) 
{
	registerGen(argc, argv, 1);

	return 0;
}