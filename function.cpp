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

void sauce::shelving(vector<int>& conv) {
	readFileFun(conv);
	//rack
	for (int t = conv[4], s = 0; t > 0, s < conv[4]; t--, s++) {
		//int s is to increment the pointer value to the weight of rack in the textfile
		//int t is the number of racks left 

		int b = conv[5 + s]; //int b is the max weight the program must try to hit
		string row; //display the weights used in that rack
		int curretnWt = 0;

		//calculate max 5 kg in rack 1
		//implement for loop in for loop
		for (int i = conv[0]; curretnWt <= b - 5 && i > 0 && row.length() < 8; i--) { //8 characters limit in a string added the minus to make sure that the next iteratio does not hit
			curretnWt += 5; //current weight value
			conv[0] = conv[0] - 1;
			row += " 5"; //add 5 if it went through this loop
		}

		for (int i = conv[1]; curretnWt <= b - 3 && i > 0 && row.length() < 8; i--) {
			curretnWt += 3;
			conv[1] = conv[1] - 1;
			row += " 3";
		}

		for (int i = conv[2]; curretnWt <= b - 2 && i > 0 && row.length() < 8; i--) {
			curretnWt += 2;
			conv[2] = conv[2] - 1;
			row += " 2";
		}

		for (int i = conv[3]; curretnWt <= b - 1 && i > 0 && row.length() < 8; i--) {
			curretnWt += 1;
			conv[3] = conv[3] - 1;//add to skip space
			row += " 1";
		}

		for (; row.length() < 8; ) {
			row += " _";
		}

		rack.push_back(row); //put strings values in rack vector to be iterated later
		rackweight.push_back(curretnWt); //store the current weight of the racks values in vector
	}
	for (int z = (conv[4] - 1); z >= 0; z--) { //vector  starts from [0]
		cout << "Rack " << (z + 1) << "-";
		cout << rack[z] << "(total: " << rackweight[z] << ")" << endl; 
	}

}


void sauce::Outbox(vector<int>& out) { //algorithm for the outstanding boxes
	shelving(out);
	cout << "Outstanding boxes: ";
	int o = 0;
	for (int p = out[0]; p > 0; p--) {
		cout << "5 "; //prints out to show which values are not used
		o = 1;
	}
	for (int p = out[1]; p > 0; p--) {
		cout << "3 ";
		o = 1;
	}
	for (int p = out[2]; p > 0; p--) {
		cout << "2 ";
		o = 1;
	}
	for (int p = out[3]; p > 0; p--) {
		cout << "1 ";
		o = 1;
	}
	if (o == 0) {
		cout << "0";
	}
}

void sauce::skip(vector<int>& coc) { //used a find algorithm from stl
	
	for (int i = 0; i < rack.size()-1; i++) {
		size_t nPos = rack[i].find("_", 0); // first occurrence
		while (nPos != string::npos)
		{
			space++;
			nPos = rack[i].find("_", nPos + 1);
		}
	}
	cout << endl << "Skip space : "<< space;
}
