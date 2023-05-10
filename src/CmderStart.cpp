/**
* CmderStart Project
* Copyright (c) 2023 Storm Lab.
*
* This program is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/

#define _CRT_SECURE_NO_WARNINGS //F you MS!!!!

#include <iostream>
#include <cstdlib>
#include <Windows.h>
#include <cstdio>

#include "CmderStart.hpp"

using namespace std;

CmderStart::CmderStart(char* Path)
{
	StartPath = Path;
}

void CmderStart::SetStartPath() const
{
	string StartCommand = "cmder " + (string)StartPath;
//	char *StartCommand = strcat(((char*)"cmder "), Path); //Buffer溢出
	system(StartCommand.c_str());
}

int main(int argc, char* argv[])
{
	CmderStart cmder(argv[1]);
	FILE* pFile = fopen("crash-log.log","w+");
	if (pFile == NULL) {
		cerr << "[Error] Can't open file stream" << endl;
		exit(0);
	}
	if (argc == 1) {
		//No args
		cerr << "[Error] Missing args" << endl;
		fputs("[Error] Missing args\n",pFile);
		exit(0);
	}
	else if (argc > 2) {
		//too many args
		cerr << "[Error] Too many args" << endl;
		fputs("[Error] Too many args\n", pFile);
		exit(0);
	}
	cout << "[Info] Welcome to CmderStart Project" << endl;
	Sleep(1500); //单纯为了假装在加载233
	cout << "[Info] Starting Cmder with path " << argv[1] << endl;
	Sleep(2000);
	cmder.SetStartPath();
	return 0;
}
