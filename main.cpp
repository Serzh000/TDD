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

	string EncryptKaisar(string str, int shift)
	{
		string result = "";

		shift %= 26;
		
		for (int i = 0; i < str.length(); i++)
		{
			if (((int)(str[i]) < 65) || ((int)(str[i]) > 122))
				result += str[i];

			if (((int)(str[i]) >= 97) && ((int)(str[i]) <= 122))
			{

				if ((int)(str[i]) + shift > 122)

					result += (char)((int)(str[i]) + shift - 26);

				else

					result += (char)((int)(str[i]) + shift);
			}

			if (((int)(str[i]) >= 65) && ((int)(str[i]) <= 90))
			{
				if ((int)(str[i]) + shift > 90)

					result += (char)((int)(str[i]) + shift - 26);

				else

					result += (char)((int)(str[i]) + shift);
			}
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

TEST(Test_DDT_Pile, Test_Cypher3)
{
	Cypher cyp;
	ASSERT_EQ("cdef", cyp.EncryptKaisar("abcd",2));
}

TEST(Test_DDT_Pile, Test_Cypher4)
{
	Cypher cyp;
	ASSERT_EQ("cdef", cyp.EncryptKaisar("abcd", 28));
}

TEST(Test_DDT_Pile, Test_Cypher5)
{
	Cypher cyp;
	ASSERT_EQ("Vhuhckd, qh krgl y vknrox!", cyp.EncryptKaisar("Serezha, ne hodi v shkolu!", 3));
}

TEST(Test_DDT_Pile, Test_Cypher6)
{
	Cypher cyp;
	ASSERT_EQ("Dpcpksl, yp szot g dsvzwf!", cyp.EncryptKaisar("Serezha, ne hodi v shkolu!", 1337));
}

int main(int argc, char* argv[])
{
	

	::testing::InitGoogleTest(&argc, argv);
	RUN_ALL_TESTS();

	

	system("pause");
	
	return 0;
}

