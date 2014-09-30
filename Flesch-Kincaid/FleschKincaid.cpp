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
void countWords(std::vector<string> *strPtr);
void countSyllables(std::vector<string> *strPtr);
bool isVowel(char c);
int wordCount=0;
int punctuationCount=0;
int syllables=0;

int main() {

	std::vector<string> list;
	string str;
	boost::char_separator<char> sep(" ",",.-!?\/|:;^&",boost::drop_empty_tokens);
	ifstream scoresFile;

	promptForFile(scoresFile, "input file:");


	while(!scoresFile.eof())
	{
		getline(scoresFile,str);
		boost::tokenizer< boost::char_separator<char> > tokens(str,sep);
		boost::tokenizer<> tok(str);

		BOOST_FOREACH (const string& t, tokens) {
			//cout << t << endl;
			list.push_back(t);
			
		}
	}

	countWords(&list);
	countSyllables(&list);
	std::cout<< "Words: "<<wordCount<<endl;
	std::cout<< "Sentences: "<<punctuationCount<<endl;
	std::cout<< "Syllables: "<<syllables<<endl;
	

    return 0;
}

void countWords(std::vector<string> *strPtr){
	
	std::vector<string> list = *strPtr;
	std::vector<string>::iterator listIterator;
	for(listIterator =list.begin();listIterator!= list.end();listIterator++){
		string str = *listIterator;
		if(isalpha(str[0]))
		{
			wordCount++;
		}
		else if((str[0] == '.') || (str[0] == '!') || (str[0] == '?'))
		{
			punctuationCount++;
		}
	}
}

void countSyllables(std::vector<string> *strPtr){

		std::vector<string> list = *strPtr;
		std::vector<string>::iterator listIterator;
		int i;
		for(listIterator =list.begin();listIterator!= list.end();listIterator++){
			string str =*listIterator;
			for(i=0;i<str.length();i++){
				char c = tolower(str[i]);
				if(isVowel(c))
				{
					if(i==0)
					{
							syllables++;
					}
					else{
							if((!isVowel(str[i-1]))&&!((c=='e')&&(i==str.length()-1)))
								syllables++;
							else if((c=='e')&&(i==str.length()-1))
								syllables++;
					}
					
				}

			}

		}
}



bool isVowel(char c){

	switch(c){
		case 'a':
		case 'e':
		case 'i':
		case 'o':
		case 'u':
		case 'y':
			return true;
		default:
			return false;

	}

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


