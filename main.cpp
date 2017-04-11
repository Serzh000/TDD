#include "gtest/gtest.h"

#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>
#include <math.h>
#include <stdlib.h>

using namespace std;

class Cypher
{
	

};

TEST(Test_DDT_Pile, Test_Open_Object)
{
	Cypher cyp;
	ASSERT_NO_FATAL_FAILURE(cyp);
}

int main(int argc, char* argv[])
{
	::testing::InitGoogleTest(&argc, argv);
	RUN_ALL_TESTS();
	system("pause");
	return 0;
}
