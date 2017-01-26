#include "testlib.h"
using namespace std;

int main()
{
	registerValidation();
	string s = inf.readToken("[a-z]{1,1000000}", "s");	
	inf.readEoln(); 
	inf.readEof();
	return 0;
}