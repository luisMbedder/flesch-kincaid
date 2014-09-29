/*
 * File: FleschKincaid.cpp
 * ----------------------
 * Name: [TODO: enter name here]
 * Section: [TODO: enter section leader here]
 * This file is the starter project for the Flesch-Kincaid problem.
 * [TODO: rewrite the documentation]
 */

#include <iostream>
#include <iterator>
#include <regex>
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
	std::vector<string> list;
	string str;
	boost::char_separator<char> sep(" ",",.-!?\/|:;^&",boost::drop_empty_tokens);//("-:;.,!&?"," ","'");

	//std::tr1::regex sepa( " " );

	ifstream scoresFile;
	promptForFile(scoresFile, "input file:");


	while(!scoresFile.eof())
{
   // scoresFile >> str;
	getline(scoresFile,str);
	boost::tokenizer< boost::char_separator<char> > tokens(str,sep);

//	 std::copy(std::tr1::sregex_token_iterator(str.begin(), str.end(), sepa, -1),
  //      std::tr1::sregex_token_iterator(), 
  //      std::ostream_iterator<std::string>(std::cout, "\n"));
	//for(Tok::iterator tok_iter = tok.begin(); tok_iter != tok.end(); ++tok_iter)
   //  std::cout << "<" << *tok_iter << "> ";
	   boost::tokenizer<> tok(str);
 //  for(boost::tokenizer<>::iterator beg=tok.begin(); beg!=tok.end();++beg){
//       cout << *beg << endl;//"\n";
//   }

	BOOST_FOREACH (const string& t, tokens) {
        cout << t << endl;
		list.push_back(t);
    }
    
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


