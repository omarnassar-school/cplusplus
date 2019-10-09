/*Author: Omar Nassar
 *Date: 10/3/19
 *This is a program that can store a list of different types of media and their attributes and uses different classes
 */

#include <iostream>
#include <cstring>
#include <vector>
#include <iomanip>
#include "media.h"
#include "games.h"
#include "movies.h"
#include "music.h"

using namespace std;

void add(vector<Media*>* media, int type); //initializing function to add media, takes in type of media
void search(vector<Media*>* media); //initializing function to search for entries
void erase(vector<Media*>* media); //initializing function

int main() {
  vector<Media*> mediaV; //vector for storing media entries
  //mediaV.push_back(NULL);
  char input[10]; //storing input
  while (true) {//while user hasn't quit
    cout << "What would you like to do? (ADD, SEARCH, DELETE, QUIT)" << endl;
    cin.get(input, 10); //getting input for what user wants to do
    cin.clear();
    cin.ignore(1000000, '\n');
    if (strcmp(input, "ADD") == 0 || strcmp(input, "add") == 0) {//if the user wants to add
      while (true) {
	cout << "What would you like to add? (MOVIE, GAME, MUSIC)" << endl;
	cin.get(input, 10); //what type of media user wants to add
	cin.clear();
	cin.ignore(1000000, '\n');
	if (strcmp(input, "MOVIE") == 0 || strcmp(input, "movie") == 0) {//if user wants to add a movie
	  add(&mediaV, 0); //call add function with vector and type
	  break;
	}
	else if (strcmp(input, "GAME") == 0 || strcmp(input, "game") == 0) {//if user wants to add a game
	  add(&mediaV, 1); //call add function with vector and type
	  break;
	}
	else if (strcmp(input, "MUSIC") == 0 || strcmp(input, "music") == 0) {//if user wants to add music
	  add(&mediaV, 2); //call add function with vector and type;
	  break;
	}
	else {//if input isn't valid
	  cout << "Invalid Input." << endl;
	}
      }
    }
    else if (strcmp(input, "SEARCH") == 0 || strcmp(input, "search") == 0) {//if user wants to searc
      search(&mediaV); //call search function with vector
    }
    else if (strcmp(input, "DELETE") == 0 || strcmp(input, "delete") == 0) {//if user wants to delete
      erase(&mediaV); //call delete function with vector
    }
    else if (strcmp(input, "QUIT") == 0 || strcmp(input, "quit") == 0) {//if user wants to quit
      break;
    }
    else {//if user doesn't input one of the options listed
      cout << "Invalid Input." << endl;
    }
  }
  
  return 0;
}

void add(vector<Media*>* media, int type) {//adding a new entry, take in vector array and the type of media
  char input[100];
  int input2;
  if (type == 0) {//if user is adding a movie
    Movies* movie = new Movies(); //making a new movie entry
    //all of the descriptions of the movie
    cout << "What is the title?" << endl;
    cin.get(movie -> getTitle(), 100);
    cin.clear();
    cin.ignore(1000000, '\n');
    cout << "When was it released?" << endl;
    cin >> *movie -> getYear();
    cin.clear();
    cin.ignore(1000000, '\n');
    cout << "Who directed this movie?" << endl;
    cin.get(movie -> getDirector(), 50);
    cin.clear();
    cin.ignore(1000000, '\n');
    cout << "How long is the movie?" << endl;
    cin >> *movie -> getDuration();
    cin.clear();
    cin.ignore(1000000, '\n');
    cout << "What is the rating?" << endl;
    cin >> *movie -> getRating();
    cin.clear();
    cin.ignore(1000000, '\n');
    media -> push_back(movie); //adding movie to the vector
  }
  if (type == 1) {//if user is adding a game
    Games* game = new Games(); //making a new game entry
    //all of the descriptions of the game
    cout << "What is it called?" << endl;
    cin.get(game -> getTitle(), 100);
    cin.clear();
    cin.ignore(1000000, '\n');
    cout << "When was it released?" << endl;
    cin >> *game -> getYear();
    cin.clear();
    cin.ignore(1000000, '\n');
    cout << "Who published it?" << endl;
    cin.get(game -> getPublisher(), 100);
    cin.clear();
    cin.ignore(1000000, '\n');
    cout << "What is the rating" << endl;
    cin >> *game -> getRating();
    cin.clear();
    cin.ignore(1000000, '\n');
    media -> push_back(game); //adding game to the vecor
  }
  if (type == 2) {//if user is adding music
    Music* music = new Music(); //making a new music entry
    //all of the descriptions of the music
    cout << "What is it called?" << endl;
    cin.get(music -> getTitle(), 100);
    cin.clear();
    cin.ignore(1000000, '\n');
    cout << "When was it released?" << endl;
    cin >> *music -> getYear();
    cin.clear();
    cin.ignore(1000000, '\n');
    cout << "Who made it?" << endl;
    cin.get(music -> getArtist(), 50);
    cin.clear();
    cin.ignore(1000000, '\n');
    cout << "How long is it?" << endl;
    cin >> *music -> getDuration();
    cin.clear();
    cin.ignore(1000000, '\n');
    cout << "Who published it?" << endl;
    cin.get(music -> getPublisher(), 100);
    cin.clear();
    cin.ignore(1000000, '\n');
    media -> push_back(music); //adding music to vector
  }
}

void search(vector<Media*>* media) {//function for searching, takes in a vector storing entries
  bool valid; //boolean for making sure input is valid
  char input[10];
  char title[100];
  int year;
  cout << "What would you like to search by? (TITLE/YEAR)" << endl;
  cin.get(input, 10); //search by either titile or year
  cin.clear();
  cin.ignore(1000000, '\n');
  if (strcmp(input, "TITLE") == 0 || strcmp(input, "title") == 0) {//if user wants to search by title
    cout << "What is the title?" << endl;
    cin.get(title, 100); //getting title
    cin.clear();
    cin.ignore(1000000, '\n');
    valid = true; //input is valid
  }
  else if (strcmp(input, "YEAR") == 0 || strcmp(input, "year") == 0) {//if user wants to search by year
    cout << "What year was it released?" << endl;
    cin >> year; //getting year
    cin.clear();
    cin.ignore(1000000, '\n');
    valid = true; //input is valid
  }
  else {//if user inputs anything else
    cout << "Invalid Input." << endl;
    valid = false;
  }
  if (valid == true) {//if input was valid
    vector<Media*>::iterator i; //iterator to go through the vector
    for (i = media -> begin(); i != media -> end(); i++) {
      if(strcmp((*i) -> getTitle(), title) == 0 || *(*i) -> getYear() == year) {//if the title or year match what was inputted
	//printing different attributes based on type
	if ((*i) -> getType() == 0) {//if it's a movie
	  cout << endl << "Type: Movie" << endl;
	  cout << "Title: " << (*i) -> getTitle() << endl;
	  cout << "Year: " << *(*i) -> getYear() << endl;
	  cout << "Director: " << dynamic_cast<Movies*>(*i) -> getDirector() << endl;
	  cout << "Duration: " << *dynamic_cast<Movies*>(*i) -> getDuration() << endl;
	  cout << "Rating: " << *dynamic_cast<Movies*>(*i) -> getRating() << endl << endl;
	}
	else if ((*i) -> getType() == 1) {//if it's a game
	  cout << endl << "Type: Game" << endl;
	  cout << "Title: " << (*i) -> getTitle() << endl;
	  cout << "Year: " << *(*i) -> getYear() << endl;
	  cout << "Publisher: " << dynamic_cast<Games*>(*i) -> getPublisher() << endl;
	  cout << "Rating: " << *dynamic_cast<Games*>(*i) -> getRating() << endl << endl;
	}
	else if ((*i) -> getType() == 2) {//if it's music
	  cout << endl << "Type: Music" << endl;
	  cout << "Title: " << (*i) -> getTitle() << endl;
	  cout << "Year: " << *(*i) -> getYear() << endl;
	  cout << "Artist: " << dynamic_cast<Music*>(*i) -> getArtist() << endl;
	  cout << "Duration: " << *dynamic_cast<Music*>(*i) -> getDuration() << endl;
	  cout << "Publisher: " << dynamic_cast<Music*>(*i) -> getPublisher() << endl << endl;
	}
      }
    }
  }
}

void erase(vector<Media*>* media) {//function for erasing entries, takes in vector
  char input2; //storing whether wants to delete
  //same method as searching
  bool valid;
  char input[10];
  char title[100];
  int year;
  cout << "What would you like to delete by? (TITLE/YEAR)" << endl;
  cin.get(input, 10);
  cin.clear();
  cin.ignore(1000000, '\n');
  if (strcmp(input, "TITLE") == 0 || strcmp(input, "title") == 0) {
    cout << "What is the title?" << endl;
    cin.get(title, 100);
    cin.clear();
    cin.ignore(1000000, '\n');
    valid = true;
  }
  else if (strcmp(input, "YEAR") == 0 || strcmp(input, "year") == 0) {
    cout << "What year was it released?" << endl;
    cin >> year;
    cin.clear();
    cin.ignore(1000000, '\n');
    valid = true;
  }
  else {
    cout << "Invalid Input." << endl;
    valid = false;
  }
  if (valid == true) {
    vector<Media*>::iterator i;
    for (i = media -> begin(); i != media -> end(); i++) {
      //cout << (*i) << endl;
      if(strcmp((*i) -> getTitle(), title) == 0 || *(*i) -> getYear() == year) {
	if ((*i) -> getType() == 0) {
	  cout << endl << "Type: Movie" << endl;
	  cout << "Title: " << (*i) -> getTitle() << endl;
	  cout << "Year: " << *(*i) -> getYear() << endl;
	  cout << "Director: " << dynamic_cast<Movies*>(*i) -> getDirector() << endl;
	  cout << "Duration: " << *dynamic_cast<Movies*>(*i) -> getDuration() << endl;
	  cout << "Rating: " << *dynamic_cast<Movies*>(*i) -> getRating() << endl << endl;
	  cout << "Are you sure you want to delete this? (y/n)" << endl; //making sure user actually wants to delete the entry
	  cin >> input2;
	  cin.clear();
	  cin.ignore(1000000, '\n');
	  if (input2 == 'y') {//if user wants to delete
	    delete *i; //deleting i from memory
	    i = media -> erase(i); //removing i from iterator
	    cout << "Entry deleted." << endl << endl;
	    i--; //going back one value because vector is now shorter
	    //return;
	  }
	  else if (input2 == 'n') {//if user doesn't want to delete
	    cout << "Entry not deleted." << endl << endl;
	  }
	  else {//if input isn't valid
	    cout << "Invalid Input." << endl;
	  }
      }
	else if ((*i) -> getType() == 1) {
	  cout << endl << "Type: Game" << endl;
	  cout << "Title: " << (*i) -> getTitle() << endl;
	  cout << "Year: " << *(*i) -> getYear() << endl;
	  cout << "Publisher: " << dynamic_cast<Games*>(*i) -> getPublisher() << endl;
	  cout << "Rating: " << *dynamic_cast<Games*>(*i) -> getRating() << endl << endl;
	  cout << "Are you sure you want to delete this? (y/n)" << endl;
	  cin >> input2;
	  cin.clear();
	  cin.ignore(1000000, '\n');
	  if (input2 == 'y') {
	    delete *i;
	    i = media -> erase(i);
	    cout << "Entry deleted." << endl << endl;
	    i--;
	    //return;
	  }
	  else if (input2 == 'n') {
	    cout << "Entry not deleted." << endl << endl;
	  }
	  else {
	    cout << "Invalid Input." << endl;
	  }
	}
	else if ((*i) -> getType() == 2) {
	  cout << endl << "Type: Music" << endl;
	  cout << "Title: " << (*i) -> getTitle() << endl;
	  cout << "Year: " << *(*i) -> getYear() << endl;
	  cout << "Artist: " << dynamic_cast<Music*>(*i) -> getArtist() << endl;
	  cout << "Duration: " << *dynamic_cast<Music*>(*i) -> getDuration() << endl;
	  cout << "Publisher: " << dynamic_cast<Music*>(*i) -> getPublisher() << endl << endl;
	  cout << "Are you sure you want to delete this? (y/n)" << endl;
	  cin >> input2;
	  cin.clear();
	  cin.ignore(1000000, '\n');
	  if (input2 == 'y') {
	    delete *i;
	    i = media -> erase(i);
	    cout << "Entry deleted." << endl << endl;
	    i--;
	    //return;
	  }
	  else if (input2 == 'n') {
	    cout << "Entry not deleted." << endl << endl;
	  }
	  else {
	    cout << "Invalid Input." << endl;
	  }
	}
      }
    }
  }
}
