/*
 * File: FleschKincaid.cpp
 * ----------------------
 * Name: [TODO: enter name here]
 * Section: [TODO: enter section leader here]
 * This file is the starter project for the Flesch-Kincaid problem.
 * [TODO: rewrite the documentation]
 */

#include <iostream>
#include <fstream>
#include "console.h"
#include <string>
#include <boost/foreach.hpp>
#include <boost/tokenizer.hpp>
using namespace std;

string promptForFile(ifstream & infile, string prompt = "");

int main() {
 /*     string text = "token, test   string";

	boost::char_separator<char> sep(", ");
	boost::tokenizer< boost::char_separator<char> > tokens(text, sep);
    BOOST_FOREACH (const string& t, tokens) {
        cout << t << "." << endl;
    }*/
	string str;
	boost::char_separator<char> sep("'");
	ifstream scoresFile;
	promptForFile(scoresFile, "input file:");
	while(!scoresFile.eof())
{
    scoresFile >> str;
	getline(scoresFile,str);
	boost::tokenizer< boost::char_separator<char> > tokens(str,sep);
	//for(Tok::iterator tok_iter = tok.begin(); tok_iter != tok.end(); ++tok_iter)
   //  std::cout << "<" << *tok_iter << "> ";
	BOOST_FOREACH (const string& t, tokens) {
        cout << t << endl;
    }
   // list.push_back(str);
}

	getline(scoresFile,str);
	

    return 0;
}


string promptForFile(std::ifstream & infile, std::string prompt){
	while (true){
		std::cout << prompt;
		std::string filename;
		std::getline(std::cin,filename);
		infile.open(filename.c_str());
		if (!infile.fail())
			return filename;
		infile.clear();
		std::cout << "Unable to open file. Try again." << std::endl;
		if (prompt == "")
			prompt = "input file:";

	}

}


