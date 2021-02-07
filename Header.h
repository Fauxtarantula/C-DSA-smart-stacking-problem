#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <list>
using namespace std;
class sauce {
public:	
	
	
	void readFileFun(vector<int> &vect);
	void shelving(vector<int> &conv);
	void Outbox(vector<int>& out);
	void skip(vector<int>& coc);

private:
	vector<string> rack;
	vector<int> rackweight;
	vector<string> boxvect;
	int count = 0;
	string box;
	int space = 0;

	
};

