#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

struct Birds{
  enum {MAX_CHAR_ARRAY_SIZE = 100};
  char name[MAX_CHAR_ARRAY_SIZE];
  char ScientificName[MAX_CHAR_ARRAY_SIZE];
  char ConservationStatus[MAX_CHAR_ARRAY_SIZE];
  char PrimaryColor[MAX_CHAR_ARRAY_SIZE];
  char Diet[MAX_CHAR_ARRAY_SIZE];
  Birds();
};

int readBirdz(Birds bird[99]);
void AddBird(Birds bird[99], int max);
void removeBird(Birds bird[99], int Index, int max);
void PrintBirdByChoice (Birds bird[99], int numBirds);
Birds::Birds(){
  for (int index = 0; index < MAX_CHAR_ARRAY_SIZE; index++) {
      name[index] = '\0';
      ScientificName[index] = '\0';
      ConservationStatus[index] = '\0';
      PrimaryColor[index] = '\0';
      Diet[index] = '\0';
    }
}

void printBirds(ostream &out, Birds bird){
    out << bird.name << ";";
    out << bird.ScientificName << ";";
    out << bird.ConservationStatus << ";";
    out << bird.PrimaryColor << ";";
    out << bird.Diet << endl;
}

void printArrayToScreen(Birds birdArray[99], int birdExamples) {
    for (int index = 0; index < birdExamples; index++) {
        cout << "Index " << index << ": ";
        printBirds(cout, birdArray[index]);
    }
}

void printArrayToFile(const char fileName[], Birds birdArray[99], int birdExamples) {
    ofstream outFile(fileName);
    for (int index = 0; index < birdExamples; index++) {
        printBirds(outFile, birdArray[index]);
    }
}

int DisplayMenu(int choice, Birds birds[99], int numBirds ){
 if (choice == 1){
   numBirds = readBirdz(birds);
 }else if (choice == 2){
   cout << numBirds<< endl;
   printArrayToScreen(birds, numBirds);
 }else if (choice == 3){
   AddBird(birds, numBirds);
   numBirds++;
 }else if (choice == 4){
   int input = 0;
   cout << "Enter index to remove: ";
   cin >> input;
   removeBird(birds, input, numBirds);
   numBirds--;
 }else if (choice == 5){
   PrintBirdByChoice(birds, numBirds);
 }else if (choice == 6){
   printArrayToFile("test.txt", birds, numBirds);
 }else if (choice == -1){
  cout << endl;
  cin.ignore(100,'\n');
}else{
 cout << "Invalid input.";

}
  return numBirds;
}

const int MAX_BIRDS=500;

Birds readBird(ifstream &inFile){
    Birds bird; 
    inFile.get(bird.name,Birds::MAX_CHAR_ARRAY_SIZE, ';');
    inFile.ignore(100,';');
    inFile.get(bird.ScientificName,Birds::MAX_CHAR_ARRAY_SIZE,';');
    inFile.ignore(100,';');
  inFile.get(bird.ConservationStatus,Birds::MAX_CHAR_ARRAY_SIZE,';');
    inFile.ignore(100,';');
  inFile.get(bird.PrimaryColor,Birds::MAX_CHAR_ARRAY_SIZE, ';');
    inFile.ignore(100,';');
  inFile.get(bird.Diet,Birds::MAX_CHAR_ARRAY_SIZE);
    inFile.ignore(100,'\n');
    // If we reached the end of the file while reading, then the entry is not valid
    return bird;
}

int readBirdz(Birds bird[99]) {
    ifstream birdFile("birds.txt");
    int numBirds = 0;
    while(birdFile.peek() != EOF && numBirds < MAX_BIRDS) {
        bird[numBirds] = readBird(birdFile);
        numBirds++;
    }
    return numBirds;
}

void AddBird(Birds bird[99], int max){
  for (int index = 0; index < max ; index++){


cin.ignore(100,'\n');
cout << "Enter Bird name: ";
cin.getline(bird[index].name, Birds::MAX_CHAR_ARRAY_SIZE);
cout << "Enter Bird Scientific name: ";
cin.getline(bird[index].ScientificName, Birds::MAX_CHAR_ARRAY_SIZE);
cout << "Enter BirdConservation status: ";
cin.getline(bird[index].ConservationStatus, Birds::MAX_CHAR_ARRAY_SIZE);
cout << "Enter Bird Primary Color: ";
cin.getline(bird[index].PrimaryColor, Birds::MAX_CHAR_ARRAY_SIZE);
cout << "Enter Bird Diet: ";
cin.getline(bird[index].Diet, Birds::MAX_CHAR_ARRAY_SIZE);
return;

}
}

void removeBird(Birds bird[99], int Index, int max){
  for (int x = Index; x < max; x++){
    bird[x] = bird[x+1];
  }
}

void PrintBirdByChoice (Birds bird[99], int numBirds){
char Input [20];
cout << "What bird color do you want? ";
cin >> Input;
for (int index = 0; index < numBirds +1; index++){

if (strcmp (Input, bird[index].PrimaryColor) == 0){
cout << "Index " << index << ": ";
printBirds(cout,bird[index]);
cout << endl;
}
}
}


int main(){

Birds birdArray[99];
int numBirds = readBirdz(birdArray);

  int choice = 0;
while(choice != -1){
  cout << "Which option would you like?: " << endl;
  cout << "1.Reload database from the file" << endl;
  cout << "2.Print database" << endl;
  cout << "3.Add new entry" << endl;
  cout << "4.Remove entry "<< endl;
  cout << "5.Print all Birds of your color choice" << endl; 
  cout << "6.Save database to the file" << endl;
  cout << "7.Enter -1 to Quit" << endl;
  cout << "Enter your choice: ";
  cin >> choice;
  numBirds = DisplayMenu(choice, birdArray, numBirds);

}
  return 0;
}
