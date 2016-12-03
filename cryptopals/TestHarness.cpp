
#include "Stdafx.h"
#include "cryptopals.h"


using namespace Cryptopals;
using namespace std;

int main() {
	char* aCStr = "49276d206b696c6c696e6720796f757220627261696e206c696b65206120706f69736f6e6f7573206d757368726f6f6d";
	std::list<char> q = Basic::hexToBase64(aCStr,96);
	std::string s = "";
	for (const auto &i : q)
	{
		s += i;
	}
	cout << s << endl;
	system("PAUSE");
	return 0;
}