// WordLadder.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<fstream>//including file library
#include<vector> //including vector library
#include<random>//including randomisation
#include<string>//including strings
#include<ctime>//including c string library
#include<algorithm>
#include<queue>
#include<stack>
#include<set>


using namespace std;
int getIndex(string, set<string>&);
class WordLadder {
private:
	queue<stack<string>> allPossibleLadder;
	string lastWord;
	string firstWord;
	set<string> words;
	set<string> usedWord;

public:
	set<string> generateAllWords(string);
	stack<string> getLadder();
	void getLadderH();

	WordLadder(string first, string last, set<string> words) {
		this->words = words;
		this->lastWord = last;
		this->firstWord = first;
		//usedWord.push_back(first);
		usedWord.insert(first);
	}
	
};
stack<string> WordLadder::getLadder() {
	stack<string> ladder;
	ladder.push(this->firstWord);

	allPossibleLadder.push(ladder);
	getLadderH();
	if (this->allPossibleLadder.empty()) {
		ladder.pop();
		return ladder;
	}
	else {
		return this->allPossibleLadder.front();
	}
}
void WordLadder::getLadderH() {
	stack<string> ladder = this->allPossibleLadder.front();
	this->allPossibleLadder.pop();

	string currentWord = ladder.top();
	
	//not net dif
	set<string> allPossibleWords = generateAllWords(currentWord);
	for (auto word : allPossibleWords) {
		stack<string> newLadder(ladder);
		newLadder.push(word);
		//cout << " \n " << word << "\n";
		this->allPossibleLadder.push(newLadder);

	}
	string nextWord;
	if (!this->allPossibleLadder.empty()) {
		ladder = this->allPossibleLadder.front();
		nextWord = ladder.top();
	}
	
	if (allPossibleLadder.empty()) {
	
		return;
	}
	else if (!nextWord.compare(lastWord)) {
		return;
	}
	else {
		getLadderH();
	}
}
set<string> WordLadder::generateAllWords(string word) {
	set<string> possibleWords;
	
	for (int i = 0; i < word.size(); i++) {
		// check this condition agiain later
		string wordP = word;
		char cOfWord = wordP.at(i);
		char cOfLast = this->lastWord.at(i);
		char start, last;
		if (cOfWord < cOfLast) {
			start = cOfWord;
			last = cOfLast;
		}
		else {
			start = cOfLast;
			last = cOfWord;
		}
		for (char c = start; c <= last; ++c) {
			string str(1, c);
			wordP.replace(i,1,str);
			if (usedWord.find(wordP) == usedWord.end())
			{
				if (getIndex(wordP, this->words) != -1) {
					
					possibleWords.insert(wordP);
					this->usedWord.insert(wordP);
				}
			}
			
			
		}
	}
	return possibleWords;
}












set<string> get_text(ifstream& get)//a funtion that puts the file into a vector and returns the vector
{
	set<string> strings;
	string d;
	while (get >> d) {
		strings.insert(d);
	}
	return strings;
}



int main()
{
	char tryAgain;
	string firstWord, secondWord;
	cout << endl << "welcome \n enter two english word to provide ladder \n";

	

	set<string> words;
	ifstream get;//reading the file
	//get.open("file1.txt");//openning the file
	get.open("EnglishWords 1.dat");
	if (!get)//checking if the file exists
	{

		cout << "loss of allocation \n";
		return 0;
	}
	words = get_text(get);//called functions
	int indexOfFirst = -1, indexOfSecond = -1;
	do {

	
	do {
		while (indexOfFirst == -1) {
			cout << "enter first word :";
			cin >> firstWord;

			indexOfFirst = getIndex(firstWord, words);
			if (indexOfFirst == -1) {
				cout << "\n no such word exist, you can try again \n";
			}

		}
		while (indexOfSecond == -1) {
		
			cout << "enter second word :";
			cin >> secondWord;
			indexOfSecond = getIndex(secondWord, words);

			if (indexOfSecond == -1) {
				cout << " \n no such word exist , you can try again \n ";
			}


		}
		if (firstWord.size() != secondWord.size()) {
			cout << "\n file size must equal try again \n";
			indexOfFirst = indexOfSecond = -1;
		}
	} while (firstWord.size() != secondWord.size());

	WordLadder wordLadder(firstWord, secondWord,words);
	stack<string> ladder = wordLadder.getLadder();

	if (ladder.empty()) {
		cout << "\n unable to find ladder \n ";
	}
	else {
		while (!ladder.empty()) {
			cout << ladder.top() << "-> ";
			ladder.pop();
		}
	}
	
	cout << "\n \n do you want to try again ? \'y\' for yes :";
	cin >> tryAgain;
	cin.clear();
	if (tryAgain == 'y') {
		indexOfFirst = indexOfSecond = -1;
	}
	} while (tryAgain == 'y');




	//cout << "first word is " << indexOfFirst << " and second word is " << indexOfSecond;

	

}
int getIndex(string word, set<string> &words) {
	set<string>::iterator it = words.find(word);
	

	if (it == words.end()) {
		return -1;
	}
	else {
		return distance(words.begin(), it);
	}
}




// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
