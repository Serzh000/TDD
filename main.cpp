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
	
	bool OpenFolder(string path)
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
			return true;
		}
		return false;
	}

	string EncryptKaisar(string str)
	{
		string result = "";

		for (int i = 0; i < str.length(); i++)
		{
			result += (char)((int)(str[i]) + 1);
		}

		return result;
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

TEST(Test_DDT_Pile, Test_Open_Folder2)
{
	Cypher cyp;
	ASSERT_FALSE(cyp.OpenFolder("NOFOLDER"));
}

TEST(Test_DDT_Pile, Test_Cypher)
{
	Cypher cyp;
	ASSERT_EQ("bcde", cyp.EncryptKaisar("abcd"));
}

int main(int argc, char* argv[])
{
	

	::testing::InitGoogleTest(&argc, argv);
	RUN_ALL_TESTS();

	

	system("pause");
	
	return 0;
}

