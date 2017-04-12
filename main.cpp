#include "gtest/gtest.h"

#include <windows.h>
#include <iostream>
#include <fstream>
#include <sstream>
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
		int key;

		hf = FindFirstFile(res.c_str(), &FindFileData);

		if (hf != INVALID_HANDLE_VALUE) 
		{
			cout << "Input key: ";
			cin >> key;

			do 
			{
				std::cout << FindFileData.cFileName << "\n";
				if (FindFileData.cFileName != "." || FindFileData.cFileName != "..")
				{
					PerformEncryption("c:\\" + path + "\\" + FindFileData.cFileName, key);
				}
					
			} while (FindNextFile(hf, &FindFileData) != 0);
			FindClose(hf);
			return true;
		}
		return false;
	}

	string EncryptKaisar(string str, int shift)
	{
		string result = "";

		if (shift>26)
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

	string DecryptKaisar(string str, int shift)
	{
		string result = "";

		if(shift>26)
			shift %= 26;

		for (int i = 0; i < str.length(); i++)
		{
			if (((int)(str[i]) < 65) || ((int)(str[i]) > 122))
				result += str[i];

			if (((int)(str[i]) >= 97) && ((int)(str[i]) <= 122))
			{

				if ((int)(str[i]) - shift < 97)

					result += (char)((int)(str[i]) - shift + 26);

				else

					result += (char)((int)(str[i]) - shift);
			}

			if (((int)(str[i]) >= 65) && ((int)(str[i]) <= 90))
			{
				if ((int)(str[i]) - shift < 65)

					result += (char)((int)(str[i]) - shift + 26);

				else

					result += (char)((int)(str[i]) - shift);
			}
		}
			
			return result;
	}

	bool PerformEncryption(string file, int key)
	{
		string str;

			if (file != "")
			{
				ifstream in(file);

				getline(in, str);
				string result = EncryptKaisar(str, key);
				in.close();

				ofstream out(file);
				out << result << endl;
				out.close();
	
				return true;
			}

		return false;		
	}

	
	
};

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

TEST(Test_DDT_Pile, Test_Decypher1)
{
	Cypher cyp;
	ASSERT_EQ("abcd", cyp.DecryptKaisar("bcde", 1));
}

TEST(Test_DDT_Pile, Test_Decypher2)
{
	Cypher cyp;
	ASSERT_EQ("abcd", cyp.DecryptKaisar("bcde", 495));
}

TEST(Test_DDT_Pile, Test_Decypher3)
{
	Cypher cyp;
	ASSERT_EQ("Serezha, ne hodi v shkolu!", cyp.DecryptKaisar("Vhuhckd, qh krgl y vknrox!", 3));
}

TEST(Test_DDT_Pile, Test_Cypher_Folder)
{
	Cypher cyp;
	EXPECT_TRUE(cyp.OpenFolder("TDD_Cypher"));
}


int main(int argc, char* argv[])
{
	

	::testing::InitGoogleTest(&argc, argv);
	RUN_ALL_TESTS();

	Cypher cyp;



	system("pause");
	
	return 0;
}




