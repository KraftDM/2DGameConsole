#include "Inputs.h"
#include <windows.h>

map<int, bool> Inputs::flagKeys = {};

bool Inputs::SetKey(int key)
{
	if (flagKeys.find(key) == flagKeys.end()) {
		flagKeys[key] = false;
		return true;
	} else return false;
}

bool Inputs::isPresed(int key)
{
	flagKeys[key] = GetAsyncKeyState(key) != 0;
	return flagKeys[key];
}

bool Inputs::isClick(int key)
{
	if (GetAsyncKeyState(key) != 0) {
		if (!flagKeys[key]) {
			flagKeys[key] = true;
			return true;
		}
	} else flagKeys[key] = false;
	return false;
}
