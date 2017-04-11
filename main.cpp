#include "gtest/gtest.h"

#include <windows.h>
#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>
#include <math.h>
#include <stdlib.h>

using namespace std;

class Cypher
{
public:
	
	void OpenFolder(string path)
	{
		WIN32_FIND_DATA FindFileData;
		HANDLE hf;
		string res = "c:\\" + path + "\\*";

		hf = FindFirstFile(res.c_str(), &FindFileData);

		if (hf != INVALID_HANDLE_VALUE) 
		{
			do 
			{
				std::cout << FindFileData.cFileName << "\n";
			} while (FindNextFile(hf, &FindFileData) != 0);
			FindClose(hf);
		}
	}

};

TEST(Test_DDT_Pile, Test_Open_Object)
{
	Cypher cyp;
	ASSERT_NO_FATAL_FAILURE(cyp);
}

TEST(Test_DDT_Pile, Test_Open_Folder)
{
	Cypher cyp;
	ASSERT_NO_FATAL_FAILURE(cyp.OpenFolder("TDD_Cypher"));
}

int main(int argc, char* argv[])
{
	

	::testing::InitGoogleTest(&argc, argv);
	RUN_ALL_TESTS();

	

	system("pause");
	
	return 0;
}
