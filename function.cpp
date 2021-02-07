#include "Header.h"
using namespace std;

int main() {
	sauce yes;

	ifstream inFile;
	inFile.open("input.txt");

	//error check
	if (inFile.fail()) {
		cerr << "Error Opening File" << endl;
		exit(1);
	}
	int count = 0;
	string box;
	vector<int> numvect;
	vector<string> boxvect;

	for (; !inFile.eof(); count++) {
		getline(inFile, box, '\n');
		boxvect.push_back(box);
	}
	for (int n = 0; n < boxvect.size(); n++) {

		string cha = boxvect[n].substr(11);
		int m = stoi(cha);
		numvect.push_back(m);

		cout << numvect[n] << endl;
	}

	//test
	/*for (int s = 0; ; s++) {
		int b = numvect[5 + s];
		cout << " "<< b;
	}*/

	for (int t = numvect[4], s= 0; t > 0, s < 3;t--, s++) {
		//yes.calculate(numvect);
		//numvect[+r] need this in recursive algorithm
		int b = numvect[5 + s];
		//rack1
		//we need to make this into a class function and pass parameters from main to function and call remainder into rack2
		vector<int> rack;
		vector<int>outstanding;
		outstanding = numvect;
		int a = 0;
		//calculate max 5 kg in rack 1
		//implement for loop in for loop
		for (int i = numvect[0]; a <= b - 5 && i > 0 && rack.size() < 4; i--) {
			a += 5;
			outstanding[0] = outstanding[0] - 1;
			rack.push_back(5);
		}

		for (int i = numvect[1]; a <= b - 3 && i > 0 && rack.size() < 4; i--) {
			a += 3;
			outstanding[1] = outstanding[1] - 1;
			rack.push_back(3);
		}

		for (int i = numvect[2]; a <= b - 2 && i > 0 && rack.size() < 4; i--) {
			a += 2;
			outstanding[2] = outstanding[2] - 1;
			rack.push_back(2);
		}

		for (int i = numvect[3]; a <= b - 1 && i > 0 && rack.size() < 4; i--) {
			a += 1;
			outstanding[3] = outstanding[3] - 1;//add to skip space
			rack.push_back(1);
		}
		cout << "Rack" << t;
		for (int z = 0; z < rack.size(); z++) {
			cout << " " << rack[z];

		}
		cout << endl;
	}
}
