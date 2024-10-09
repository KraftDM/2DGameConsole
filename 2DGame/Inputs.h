#ifndef INPUT_H
#define INPUT_H

#include <map>

using namespace std;

class Inputs
{
	private:
	static map<int, bool> flagKeys;

	Inputs() = delete;
	~Inputs() {};

	public:
	static bool SetKey(int key);
	static bool isPresed(int key);
	static bool isClick(int key);
};

#endif