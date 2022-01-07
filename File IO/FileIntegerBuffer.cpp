#include <fstream>
#include <iostream>
#include <string>
#include <iomanip>
#include "FileIntegerBuffer.h"
using namespace std;

bool FileIntegerBuffer::store(string filename, 
	int columnWidth, int numberOfColumns) {
	ofstream fout;
	fout.open(filename);
	if (fout.is_open()) {
		for (int i = 0; i < dataLength; ++i) {
			if (i > 0 && (i % numberOfColumns) == 0)
				fout << endl;
			fout << setw(columnWidth) << data[i];
		}
		fout << endl;
		fout.close();
		return true;
	} else
		return false;
}

int FileIntegerBuffer::load(string filename) {
	ifstream fin;
	int datum = 0;
	int total = 0;
	fin.open(filename);
	if (fin.is_open()) {
		while(fin >> datum) {
			while (fin.fail()) {
				fin.clear();
				fin.ignore(999, '\n');
				fin >> datum;
			}
			total += add(datum);
		}
 		fin.close();
		return total;
	} else
		return -1;
}
