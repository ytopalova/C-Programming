// Lab 1.cpp : Defines the entry point for the application.
//

#include "Lab 1.h"


#if usingNamespaces == 0
int main()
{
#pragma message("Not using namespaces")
	std::cout << "Hello world!" << std::endl;
	return 0;
}
#elif usingNamespaces 
using namespace std;
int main()
{
#pragma message("Using namespaces")
	cout << "Hello world!" << endl;
	return 0;
}
#endif

