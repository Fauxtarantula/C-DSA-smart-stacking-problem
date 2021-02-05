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
		//cout << vect[n] << endl;
	}
	if (boxvect.size() > 4) {
		string cha = boxvect[4].substr(13);
		int m = stoi(cha);
		vect.push_back(m);
		//cout << vect[4] << endl;
	}
	for (int n = 5; n < boxvect.size(); n++) {

		string cha = boxvect[n].substr(25);
		int m = stoi(cha);
		vect.push_back(m);
		//cout << vect[n] << endl;
	}

}

void sauce::shelf(vector<int>& conv) {
	readFileFun(conv);
	//int p= conv[4];
	//rack
	for (int t = conv[4], s = 0; t > 0, s < conv[4]; t--, s++) {
		//numvect[+r] need this in recursive algorithm
		int end = conv.size();
		int b = conv[5+s];
		string row;
		int a = 0;
		int numberofskip = 0;

		//int a = 0;
		//calculate max 5 kg in rack 1
		//implement for loop in for loop
		for (int i = conv[0]; a <= b - 5 && i > 0 && row.length() < 8; i--) { //8 characters limit in a string
			a += 5;
			conv[0] = conv[0] - 1;
			row += " 5";
		}

		for (int i = conv[1]; a <= b - 3 && i > 0 && row.length() < 8; i--) {
			a += 3;
			conv[1] = conv[1] - 1;
			row += " 3";
		}

		for (int i = conv[2]; a <= b - 2 && i > 0 && row.length() < 8; i--) {
			a += 2;
			conv[2] = conv[2] - 1;
			row += " 2";
		}

		for (int i = conv[3]; a <= b - 1 && i > 0 && row.length() < 8; i--) {
			a += 1;
			conv[3] = conv[3] - 1;//add to skip space
			row += " 1";
		}

		for (; row.length() < 8; ) {
			row += " _";
		}

		rack.push_back(row);
		rackweight.push_back(a);
	}
	for (int z = (conv[4]-1); z >= 0; z--) { //vector  starts from [0]
		cout << "Rack " << (z+1) << "-";
		cout << rack[z] <<"(total: " << rackweight[z] << ")"<< endl;
	}

}


void sauce::Outbox(vector<int>& out) {
	shelf(out);
	cout << "Outstanding boxes: ";
	for (int p = out[0]; p > 0; p--) {
		cout << "5 ";
		//out[i]
	}
	for (int p = out[1]; p > 0; p--) {
		cout << "3 ";
		//out[i]
	}
	for (int p = out[2]; p > 0; p--) {
		cout << "2 ";
		//out[i]
	}
	for (int p = out[3]; p > 0; p--) {
		cout << "1 ";
		//out[i]
	}
}

void sauce::skip(vector<int>& coc) {
	shelf(coc);
	int space = 0;
	cout << "Skip space : ";
	for (int i = 0; i < 2;i++) {
		string str1 = " _";

		// Find first occurrence of "geeks" 
		size_t found = rack[i].find(str1);
		if (found != string::npos)
			cout << space+1 << endl;

		// Find next occurrence of "geeks". Note here we pass 
		// "geeks" as C style string. 
		/*char arr[] = "geeks";
		found = str.find(arr, found + 1);
		if (found != string::npos)
			cout << "Next occurrence is " << found << endl;*/
	}
}
