#include "Header.h"

using namespace std;


void sauce::readFileFun(vector<int>& vect) {
	ifstream inFile;
	inFile.open("input.txt");

	//error check
	if (inFile.fail()) {
		cerr << "Error Opening File" << endl;
		exit(1);
	}
	int count = 0;
	string box;
	vector<string> boxvect;


	for (; !inFile.eof(); count++) {
		getline(inFile, box, '\n');
		boxvect.push_back(box);
	}

	for (int n = 0; n < 4; n++) {

		string cha = boxvect[n].substr(11);
		int m = stoi(cha);
		vect.push_back(m);
		cout << vect[n] << endl;
	}
	if (boxvect.size() > 4) {
		string cha = boxvect[4].substr(13);
		int m = stoi(cha);
		vect.push_back(m);
		cout << vect[4] << endl;
	}
	for (int n = 5; n < boxvect.size(); n++) {

		string cha = boxvect[n].substr(25);
		int m = stoi(cha);
		vect.push_back(m);
		cout << vect[n] << endl;
	}

}

void sauce::shelf(vector<int>& conv) {
	readFileFun(conv);
	//int p= conv[4];
	for (int t = conv[4], s = 0; t > 0, s < conv[4]; t--, s++) {
		//numvect[+r] need this in recursive algorithm
		int b = conv[5 + s];
		//rack
		vector<int> rack;
		
		int a = 0;
		//calculate max 5 kg in rack 1
		//implement for loop in for loop
		for (int i = conv[0]; a <= b - 5 && i > 0 && rack.size() < 4; i--) {
			a += 5;
			conv[0] = conv[0] - 1;
			rack.push_back(5);
		}

		for (int i = conv[1]; a <= b - 3 && i > 0 && rack.size() < 4; i--) {
			a += 3;
			conv[1] = conv[1] - 1;
			rack.push_back(3);
		}

		for (int i = conv[2]; a <= b - 2 && i > 0 && rack.size() < 4; i--) {
			a += 2;
			conv[2] = conv[2] - 1;
			rack.push_back(2);
		}

		for (int i = conv[3]; a <= b - 1 && i > 0 && rack.size() < 4; i--) {
			a += 1;
			conv[3] = conv[3] - 1;//add to skip space
			rack.push_back(1);
		}
		cout << "Rack" << t;
		for (int z = 0; z < rack.size(); z++) {
			cout << " " << rack[z];
		}
		cout << endl;
	}
}

void sauce::Outbox(vector<int>& out) {
	shelf(out);
	for (int i = 0; i < 4;i++) {
		cout << out[i];
	}
}
