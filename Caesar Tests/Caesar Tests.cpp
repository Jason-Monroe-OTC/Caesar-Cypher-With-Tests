#include "pch.h"
#include "CppUnitTest.h"
#include "../Cypher.h"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace CaesarTests
{
	TEST_CLASS(CaesarTests)
	{
	public:
		
		TEST_METHOD(Decode_Returns_Possibilities_with_One_Correct)
		{
			//Arrange
			Cypher cypher;
			string encodedMessage = "QJJQSA QJ TQMD!";
			bool matchFound = false;

			//Act
			vector<string> possibilities = cypher.Decode(encodedMessage);

			//Assert
			for (int index = 0; index < possibilities.size(); index++)
			{
				if (possibilities.at(index) == "ATTACK AT DAWN!")
				{
					matchFound = true;
				}
			}

			Assert::IsTrue(matchFound);
		}
	};
}
