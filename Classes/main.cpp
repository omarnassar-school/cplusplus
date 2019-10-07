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
void search(vector<Media*>* media);
void erase(vector<Media*>* media);

int main() {
  vector<Media*> mediaV;
  //mediaV.push_back(NULL);
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
      search(&mediaV);
    }
    else if (strcmp(input, "DELETE") == 0 || strcmp(input, "delete") == 0) {
      erase(&mediaV);
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
    cout << "Who published it?" << endl;
    cin.get(music -> getPublisher(), 100);
    cin.clear();
    cin.ignore(1000000, '\n');
    media -> push_back(music);
  }
}

void search(vector<Media*>* media) {
  bool valid;
  char input[10];
  char title[100];
  int year;
  cout << "What would you like to search by? (TITLE/YEAR)" << endl;
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
      if(strcmp((*i) -> getTitle(), title) == 0 || *(*i) -> getYear() == year) {
	if ((*i) -> getType() == 0) {
	  cout << endl << "Type: Movie" << endl;
	  cout << "Title: " << (*i) -> getTitle() << endl;
	  cout << "Year: " << *(*i) -> getYear() << endl;
	  cout << "Director: " << dynamic_cast<Movies*>(*i) -> getDirector() << endl;
	  cout << "Duration: " << *dynamic_cast<Movies*>(*i) -> getDuration() << endl;
	  cout << "Rating: " << *dynamic_cast<Movies*>(*i) -> getRating() << endl << endl;
	}
	else if ((*i) -> getType() == 1) {
	  cout << endl << "Type: Game" << endl;
	  cout << "Title: " << (*i) -> getTitle() << endl;
	  cout << "Year: " << *(*i) -> getYear() << endl;
	  cout << "Publisher: " << dynamic_cast<Games*>(*i) -> getPublisher() << endl;
	  cout << "Rating: " << *dynamic_cast<Games*>(*i) -> getRating() << endl << endl;
	}
	else if ((*i) -> getType() == 2) {
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

void erase(vector<Media*>* media) {
  char input2;
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
      if(strcmp((*i) -> getTitle(), title) == 0 || *(*i) -> getYear() == year) {
	if ((*i) -> getType() == 0) {
	  cout << endl << "Type: Movie" << endl;
	  cout << "Title: " << (*i) -> getTitle() << endl;
	  cout << "Year: " << *(*i) -> getYear() << endl;
	  cout << "Director: " << dynamic_cast<Movies*>(*i) -> getDirector() << endl;
	  cout << "Duration: " << *dynamic_cast<Movies*>(*i) -> getDuration() << endl;
	  cout << "Rating: " << *dynamic_cast<Movies*>(*i) -> getRating() << endl << endl;
	  cout << "Are you sure you want to delete this? (y/n)" << endl;
	  cin >> input2;
	  cin.clear();
	  cin.ignore(1000000, '\n');
	  if (input2 == 'y') {
	    delete *i;
	    i = media -> erase(i);
	    cout << "Entry deleted." << endl << endl;
	    return;
	  }
	  else if (input2 == 'n') {
	    cout << "Entry not deleted." << endl << endl;
	  }
	  else {
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
	    return;
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
	    return;
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
