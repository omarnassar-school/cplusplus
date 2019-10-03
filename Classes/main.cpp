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

void add(vector<Media*>* media, int type);
void search(char* title, vector<Media*>* media);
void erase(char* title, vector<Media*>* media);

int main() {
  vector<Media*> mediaV;
  char input[10];
  char input2[100];
  while (true) {
    cout << "What would you like to do? (ADD, SEARCH, DELETE, QUIT)" << endl;
    cin.get(input, 10);
    cin.clear();
    cin.ignore(1000000, '\n');
    if (strcmp(input, "ADD") == 0 || strcmp(input, "add") == 0) {
      while (true) {
	cout << "What would you like to add? (MOVIE, GAME, MUSIC)" << endl;
	cin.get(input, 10);
	cin.clear();
	cin.ignore(1000000, '\n');
	if (strcmp(input, "MOVIE") == 0 || strcmp(input, "movie") == 0) {
	  add(&mediaV, 0);
	  break;
	}
	else if (strcmp(input, "GAME") == 0 || strcmp(input, "game") == 0) {
	  add(&mediaV, 1);
	  break;
	}
	else if (strcmp(input, "MUSIC") == 0 || strcmp(input, "music") == 0) {
	  add(&mediaV, 2);
	  break;
	}
	else {
	  cout << "Invalid Input." << endl;
	}
      }
    }
    else if (strcmp(input, "SEARCH") == 0 || strcmp(input, "search") == 0) {
      cout << "Enter the title." << endl;
      cin.get(input2, 100);
      cin.clear();
      cin.ignore(1000000, '\n');
      search(input2, &mediaV);
    }
    else if (strcmp(input, "DELETE") == 0 || strcmp(input, "delete") == 0) {
      cout << "What would you like to delete?" << endl;
      cin.get(input2, 100);
      cin.clear();
      cin.ignore(1000000, '\n');
      erase(input2, &mediaV);
    }
    else if (strcmp(input, "QUIT") == 0 || strcmp(input, "quit") == 0) {
      break;
    }
    else {
      cout << "Invalid Input." << endl;
    }
  }
  
  return 0;
}

void add(vector<Media*>* media, int type) {
  char input[100];
  int input2;
  cout << "adding ";
  if (type == 0) {
    cout << "movie" << endl;
    Movies* movie = new Movies();
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
    media -> push_back(movie);
  }
  if (type == 1) {
    cout << "game" << endl;
    Games* game = new Games();
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
    media -> push_back(game);
  }
  if (type == 2) {
    cout << "music" << endl;
    Music* music = new Music();
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
    cout << "Who published it" << endl;
    cin.get(music -> getPublisher(), 100);
    cin.clear();
    cin.ignore(1000000, '\n');
    media -> push_back(music);
  }
}

void search(char* title, vector<Media*>* media) {
  cout << "searching for " << title << endl;
  vector<Media*>::iterator i;
  for (i = media -> begin(); i != media -> end(); i++) {
    if(strcmp((*i) -> getTitle(), title) == 0) {
      if ((*i) -> getType() == 0) {
	cout << endl << "The Title: " << (*i) -> getTitle() << endl;
	cout << "The Year: " << *(*i) -> getYear() << endl;
	cout << "Director: " << dynamic_cast<Movies*>(*i) -> getDirector() << endl;
	cout << "Duration: " << *dynamic_cast<Movies*>(*i) -> getDuration() << endl;
	cout << "Rating: " << *dynamic_cast<Movies*>(*i) -> getRating() << endl << endl;
      }
    }
  }
}

void erase(char* title, vector<Media*>* media) {
  cout << "deleting " << title << endl;
}
