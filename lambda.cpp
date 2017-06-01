#include "iostream"
#include <wtypes.h>
#include <algorithm> 
using namespace std;

#define  MAX_NAME  32
struct stTest
{
	stTest(DWORD dwUserID,  char *pszUserName)
	{
		this->dwUserID = dwUserID;
		memcpy(this->szUserName, pszUserName, strlen(pszUserName)+1);
	}
	char szUserName[MAX_NAME];
	DWORD dwUserID;
};

void PrintOutStTestInfo(stTest(&arrayTest)[3])
{
	for each (stTest var in arrayTest)
	{
		cout << var.dwUserID << "    name=  " << var.szUserName << endl;
	}
}

bool SortID(const stTest &val1, const stTest &val2)
{
	return val1.dwUserID < val2.dwUserID;
}

bool SortName(const stTest &val1, const stTest &val2)
{
	return strcmp(val1.szUserName, val2.szUserName) == 1 ? true : false;
}

 int main()
 {
 	//Lambda way
  	stTest arrayTest[] = { stTest(10, "xsk"), stTest(20, "Axsk"), stTest(6, "test") };
 	std::sort(arrayTest, arrayTest + 3, [](const stTest &val1, stTest &val2){return val1.dwUserID < val2.dwUserID; });
 	PrintOutStTestInfo(arrayTest);
 	std::sort(arrayTest, arrayTest + 3, [](const stTest &val1, stTest &val2){return strcmp(val1.szUserName, val2.szUserName)== 1? true:false; });
 	PrintOutStTestInfo(arrayTest);
 
 	//normal way
 	stTest arrayTest2[] = { stTest(22, "b"), stTest(17, "a"), stTest(25, "test") };
 	std::sort(arrayTest2, arrayTest2 + 3, SortID);
 	PrintOutStTestInfo(arrayTest2);
 	std::sort(arrayTest2, arrayTest2 + 3, SortName);
 	PrintOutStTestInfo(arrayTest2);
 }