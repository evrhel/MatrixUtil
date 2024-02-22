#include <cstdio>
#include <string>

#include "test.h"

extern Test getVector2Test(const std::string &test);
extern Test getVector3Test(const std::string &test);
extern Test getVector4Test(const std::string &test);
extern Test getQuaternionTest(const std::string &test);

static Test findTest(const std::string &test)
{
	Test r;

	r = getVector2Test(test);
	if (r) return r;

	r = getVector3Test(test);
	if (r) return r;

	r = getVector4Test(test);
	if (r) return r;

	r = getQuaternionTest(test);
	if (r) return r;

	return nullptr;
}

int main(int argc, char *argv[])
{
	if (argc < 2)
	{
		printf("Usage: %s <test>\n", argv[0]);
		return 1;
	}
	
	Test test = findTest(argv[1]);
	if (test)
	{
		test();
		return 0;
	}
	printf("Unknown test: %s\n", argv[1]);
	return 1;
}
