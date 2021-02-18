#include <iostream>
#include<fstream>
#include<vector>
#include<random>
#include<string>
#include<queue>
#include<stack>
#include<set>

//peace-zeros

using namespace std;
int getIndex(string, set<string>&);
class WordLadder {
private:
	queue<vector<string>> allPossibleLadder;
	string lastWord;
	string firstWord;
	set<string> words;
	set<string> usedWord;



public:
	set<string> generateAllWords(string);
	vector<string> getLadder();
	void getLadderH();

	WordLadder(string first, string last, set<string> words) {
		this->words = words;
		this->lastWord = last;
		this->firstWord = first;
		//usedWord.push_back(first);
		usedWord.insert(first);
	}

};
vector<string> WordLadder::getLadder() {
	vector<string> ladder;
	ladder.push_back(this->firstWord);
	//ladder.push();

	allPossibleLadder.push(ladder);
	getLadderH();
	if (this->allPossibleLadder.empty()) {
		//ladder.pop();
		ladder.pop_back();
		return ladder;
	}
	else {
		return this->allPossibleLadder.front();
	}
}
void WordLadder::getLadderH() {
	vector<string> ladder = this->allPossibleLadder.front();
	this->allPossibleLadder.pop();

	//string currentWord = ladder.top();
	string currentWord = ladder.back();

	//not net dif
	set<string> allPossibleWords = generateAllWords(currentWord);
	for (auto word : allPossibleWords) {
		vector<string> newLadder(ladder);
		//newLadder.push(word);
		newLadder.push_back(word);
		//cout << " \n " << word << "\n";
		this->allPossibleLadder.push(newLadder);

	}
	string nextWord;
	if (!this->allPossibleLadder.empty()) {
		ladder = this->allPossibleLadder.front();
		//nextWord = ladder.top();
		nextWord = ladder.back();
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
		/*char cOfWord = wordP.at(i);
		char cOfLast = this->lastWord.at(i);
		char start, last;
		if (cOfWord < cOfLast) {
			start = cOfWord;
			last = cOfLast;
		}
		else {
			start = cOfLast;
			last = cOfWord;
		}*/
		for (char c = 'a'; c <= 'z'; ++c) {
			string str(1, c);
			wordP.replace(i, 1, str);
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
