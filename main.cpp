#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

bool isStartFrom(char c, char *s) {
	if (s[0] == c)
		return true;
	else
		return false;
}


void getBufferFromFile(char *path, char *buffer, int size,
		vector<char*>*out_data) {

	FILE *file;
	FILE *out_f;
	out_f=fopen("out.txt","w");
	buffer = new char[size];
	out_data->clear();
	file = fopen(path, "r");

	if (!file) {
		printf("Ошибка открытия файла\n");

	} else if (file) {
		while (fgets(buffer, size, file) != NULL) {

			if (isStartFrom('R', buffer) || isStartFrom('Z', buffer) ) {
				out_data->push_back(buffer);
				printf(buffer);
				fputs(buffer,out_f);
			}
			//buffer="";

		}
		fclose(file);
		fclose(out_f);
	}

}

int main(int argc, char **argv) {

	char *path = "countries.txt";
	vector<char*> out_data;
	char buffer;
	int size = 512;
	getBufferFromFile(path, &buffer, size, &out_data);
	//writeFile("out.txt",&out_data);

	//cin.get();
}

