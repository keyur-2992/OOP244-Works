/*
*****************************************************************************
						  Workshop 1 Lab
Full Name  : keyurkumar shankarlal patel
Student ID#: 170852214
Email      : kpatel453@myseneca.ca
Section    : ZAA

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
*****************************************************************************
*/
#ifndef SDDS_WORDS_H
#define SDDS_WORDS_H
namespace sdds {

	const int MAX_WORD_LEN = 21;

	struct Word {
		char letters[MAX_WORD_LEN];
		int count;
	};

	int searchWords(const Word words[], int num, const char word[]);
	int readWord(char* word, FILE* fptr, int maxLen);
	void addWord(Word words[], int* index, const char newWord[]);
	void title(const char* value, int len);
	void endList();
	void totalWordsStat(int totNoWrds, int totalOverAll, int longestWord);
	void print(const Word* w, int gotoNextLine, int len);
	int findMaxLen(const Word words[], int noOfWords);
	void listWords(const Word words[], int noOfWords, const char* theTitle);
	void swap(Word* p1, Word* p2);
	void sort(Word words[], int cnt, int sortType);
	int totalCount(const Word* words, int num);
	void wordStats(const char* filename);
	void programTitle();

	

}
#endif