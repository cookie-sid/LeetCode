// including necessary libraries
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iostream>
#include <sstream>
#include <unordered_map>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

class mostActiveCookiesFinder {

	private:
		string fileName, date;
		ifstream file;
		vector<vector<string>> cookies;
		vector<string> mostActiveCookies;
		unordered_map<string,unordered_map<string,int>> cookieLog;

		bool openFile() {

			this -> file.open(this -> fileName);
		
			if(!file.is_open()) {
				return false;
			}
			else {
				return true;
			}

		};

		bool readDataFromFile() {

			if(!openFile()) {
				cout<<"Invalid filename.";
				return false;
			}

			vector<string> row; //temporary variable to read current row
			string line, word; //temporary variables to get lines and words from the line
			bool firstRow = true; //first row is column names so we dont take that

			while(getline(this -> file,line)) {

				//skipping the firstRow
				if(firstRow) {
					firstRow = false;
					continue;
				}

				//clearing the row for taking fresh row as input
				row.clear();

				//splitting line at ',' and adding words to the row
				stringstream str(line);
				while(getline(str,word,',')) {
					row.push_back(word);
				}
				this -> cookies.push_back(row);
			}
			return true;

		}

		bool createMap() {

			if(!readDataFromFile()) {
				return false;
			}
			
			//creating a map with date as key and a map with cookie names
			//and their frequencies as value
			for(auto singleCookie : this -> cookies) {
				string cookieName = singleCookie[0];
				string cookieTS = singleCookie[1];
				string cookieDate = cookieTS.substr(0,10);
				this -> cookieLog[cookieDate][cookieName] += 1;
			}

			return true;

		}

		bool getMostActiveCookies() {

			if(!createMap()) {
				return false;
			}

			if(this -> cookieLog[this -> date].size() == 0) {
				cout<<"There are no cookies logged for the specified date."<<endl;
				return false;
			}

			//getting maximum frequency from the map for that date
			int maxFreq = 0;
			for(auto cookies : this -> cookieLog[this -> date]) {
				maxFreq = max(maxFreq,cookies.second);
			}

			//finding all cookies with maximum frequency
			for(auto cookies : this -> cookieLog[this -> date]) {
				if(maxFreq == cookies.second)
					this -> mostActiveCookies.push_back(cookies.first);
			}

			return true;
		}


	public:

		mostActiveCookiesFinder(string fileName, string date) {
			this -> fileName = fileName;
			this -> date = date;
		}

		void displayMostActiveCookies() {
			
			if(!getMostActiveCookies()) {
				return;
			}

			for(auto cookie : mostActiveCookies) {
				cout<<cookie<<endl;
			}
		}

};

int main(int argCount, char* args[]) {

	string fileName = args[1];
	string date = args[3];
	cout<<"Filename :"<<fileName<<endl;
	cout<<"Date entered: "<<date<<endl;

	mostActiveCookiesFinder finder(fileName,date);
	finder.displayMostActiveCookies();

}
