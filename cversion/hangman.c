// hangman.c - C game based on hangman
// Author - James Birchall
// Date - 7th October 2012

/**
    Scratchpad


    Game steps:
        Welcome message
        Open wordlist file & read into memory until EOF, then close file
        Open the consecutive hangman stage files and again read into memory until EOF, the close files
        Above points will be in main and shared to methods needing them

        Show menu - Options: New Game, Highscores (how far you get through hangman before dying), Quit
        Exit:
            de allocate all memory used and quit game
        Highscores:
            Read in highscores file and display to screen
        New game:
            Show hangman stage x (defined by stage counter)
            Choose word from wordlist at random
            Count characters and show X '_ _ _''s - these get overwritten by correct answers to finding word
            Prompt player to enter character (a-z or A-Z), all gets lowercased anyway
            Check against word, one character at time
                If match found
                    Add new characters to list above where appropriate
                    Continue
                else
                    update stages
            If stages = end
                Display hangman final
                Check score against highscores list
                If high enough (greater than top 10), add to highscores file appropriately
                quit to main menu
            If wordslist = done
                Display hangman with wordlist
                Congrats player
                Ask if want to continue (y/n)
                    n = highscores bit above
                    exit
                else
                    reset wordlist choice, recount and reset things
 **/

#include <stdio.h>
#include <stdlib.h>

struct fileData{
    long fileSize;
    char *data;
};

void welcome();
char *readFile(char filename[], struct fileData *);    //DONE - can read in complete file and allocate memory!
char *getWord(struct fileData *, int);
int getWordCount(struct fileData*);
void printFile(char *, int);
int mainMenu();
void welcome();
int promptPlayer();





long lastFileSize = 0;

int main(int argc, char *argv[]){

    int gameOver = 0;

    /** -- Code for reading files works!
    char *wordlist;
    //test file in routine
    wordlist = readFile("wordlist");
    printf("\nWordlist:\n%s", wordlist);
    printf("\n");
    free(wordlist);**/

    /**
        Set wordlist pointer - this will be used to hold wordlist array and all words loaded


    **/

    char *currentWord = NULL;
    struct fileData wordlistLoaded;
    struct fileData *wordListLoadedPointer = &wordlistLoaded;
    wordlistLoaded.data = readFile("wordlist", wordListLoadedPointer);
    int wordCount = getWordCount(wordListLoadedPointer);
    currentWord = getWord(wordListLoadedPointer, 2);

    //printFile(wordlistLoaded.data, wordlistLoaded.fileSize);

//    load hangman files
    struct fileData stage1file;
    struct fileData stage2file;
    struct fileData stage3file;
    struct fileData stage4file;
    struct fileData *stage1filePointer = &stage1file;
    struct fileData *stage2filePointer = &stage2file;
    struct fileData *stage3filePointer = &stage3file;
    struct fileData *stage4filePointer = &stage4file;
    stage1file.data = readFile("hms1.txt", stage1filePointer);
    stage2file.data = readFile("hms2.txt", stage2filePointer);
    stage3file.data = readFile("hms3.txt", stage3filePointer);
    stage4file.data = readFile("hms4.txt", stage4filePointer);

    struct fileData *currentStage = &stage1file;    //this variable will be changed during the running of hangman

    welcome();

    while(gameOver != 1){
        //Display hangman stage and
        printFile(currentStage->data, currentStage->fileSize);

        int playerInput = promptPlayer();

        printf("%d", playerInput);

        //check value agains word - new function int checkWord(char)
        //this method will loop through

        exit(0);
    }

    //printFile(stage1filePointer->data, stage1filePointer->fileSize);
    //printFile(stage2filePointer->data, stage2filePointer->fileSize);
    //printFile(stage3filePointer->data, stage3filePointer->fileSize);
    //printFile(stage4filePointer->data, stage4filePointer->fileSize);


    //Now ready to start the hangman game!


    free(stage1filePointer);
    free(stage2filePointer);
    free(stage3filePointer);
    free(stage4filePointer);
    free(wordListLoadedPointer);
    free(currentWord);
    return 0;
}

char *readFile(char filename[], struct fileData *fileStructPointer){

    FILE *filein;
    char *buffer;

    if((filein = fopen(filename, "r")) == NULL){
        printf("Problem opening %s", filename);
        return NULL;
    }

    //read in number of bytes by running through file to end and then use ftell to get current postiion in stream in bytes
    fseek(filein, 0L, SEEK_END);

    fileStructPointer->fileSize = ftell(filein);

    //set back to start of file
    fseek(filein, 0L, SEEK_SET);

    //allocate storage for file
    if((buffer = (char*)calloc(fileStructPointer->fileSize, sizeof(char))) == NULL){
        printf("Problem allocating memory %s", filename);
        return NULL;
    }

    //read in file properly now
    fread(buffer, sizeof(char), fileStructPointer->fileSize, filein);

    //close file
    fclose(filein);

    printf("Read in %s\n", filename);

    return buffer;
}

int getWordCount(struct fileData *fileStructPointer){
    int wordCount = 1;

    for(int i = 0; i < fileStructPointer->fileSize; i++){
        if((fileStructPointer->data[i]) == '\n')
            wordCount++;
    }

    return wordCount;
}

char *getWord(struct fileData *fileStructPointer, int wordNumber){
    //return pointer to word!
    int currentWord = 1;
    char *wordStart;

    for(int i = 0; i < fileStructPointer->fileSize; i++){
        if((fileStructPointer->data[i]) == '\n')
            currentWord++;

        if(currentWord == wordNumber){
            wordStart = &fileStructPointer->data[i+1];
            return wordStart;
        }
    }

    return 0;
}

void printFile(char *file, int size){
    printf("\n");
    for(int i = 0; i < size; i++){
        printf("%c", file[i]);
    }
    printf("\n");
}

void welcome(){
	printf("\n\nWelcome to Terminal Hangman\n");
	printf("\nThis version brought to you by James Birchall\n");
	printf("\nSmee Studios 2012\n\n");
}

int promptPlayer(){
  int scannedNumber = 0;
  int newLineDiscard = 0;
  int wrong = 0;

  while(scannedNumber == 0){
    if(0 == wrong)
      printf("Please enter a value a-z: ");
    else
      printf("Invalid character, Please enter a value a-z: ");

    //make scanner here to get character and discard the newline read
    scanf("%c", &scannedNumber);
    scanf("%c", &newLineDiscard);   //write out newline to discard it quickly
    //scanf("%s");
    wrong = 1;
  }

  return scannedNumber;
}
