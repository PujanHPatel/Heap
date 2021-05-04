/* Take input from user or file and sort it into a Heap Tree
 * Author: Pujan Patel
 * Date: 5/1/2021
 * recived help from Ethan Wang and GeeksForGeeks
 */
#include <iostream>
#include <cmath>
#include <cstring>
#include <fstream>
#include <cstdlib>

using namespace std;
//Function Prototypes
void heap (int* array, int input, int count);
void build (int* array, int count);
void printree (int* array, int count, int input, int input2); 

int main() {
  char* input = new char[50];
  cout << "FILE or CONSOLE input" << endl;
  cin >> input;
  int count = 0;
  int* array = new int[250];
  //if console input
  if(strcmp(input, "CONSOLE") == 0) {
    cout << "Enter Number seperated with space" << endl;
    char* input2 = new char[250];
    cin >> input2;
    char* token = strtok(input2, " ");
    int index = 1;
    while(token != NULL) {
      array[index] = atoi(token);
      token = strtok(NULL, " ");
      index++;
      count++;
    }
  }
  //if file input
  else if (strcmp(input, "FILE") == 0) {
    cout << "Filename?" << endl;
    char* filename = new char[50];
    cin.getline(filename, 50);
    ifstream inFile;
    inFile.open(filename);
    char* input2 = new char[250];
    int count2 = 0;
    int index2 = 1;
    while (inFile >> count2) {
      array[index2] = count2;
      index2++;
      count++;
    }
  }
  //builds Heap and prints Tree
  build(array, count);
  cout << "Tree" << endl;
  printree(array, count, 0, 1); 
  cout << " " << endl; 
  cout << "Heap Output: ";
  for (int i = count; i > 0; i--) {
    cout << array[1] << " "; 
    array[1] = array[i];
    array[i] = 0; 
    build(array, i);
    array[i] = array[i - 1]; 
  }  
}
//sort Heap
void heap (int* array, int input, int count) {
  int index;
  int temp;
  temp = array[input];
  index = input*2;
  while (index <= count) {
    if (array[index+1] > array[index] && index < count)
      index = index + 1;
    if (temp > array[index])
      break;
    else if (temp <= array[index]) {
      array[index/2] = array[index];
      index = 2 * index;
    }
  }
  array[index/2] = temp;
  return; 
}

//build heap
void build (int* array, int count) {
  int i;
  for(i = count/2; i >= 1; i--) {
    heap(array, i, count); 
  }  
}

//print max Heap Tree 
void printree (int* array, int count, int input, int input2) {
  int leftposition = 2*input2;
  int rightposition = 2*input2+1;
  if (rightposition <= count) {
    printree(array, count, input+1, rightposition); 
  }
  int current = input;
  while (input > 0) {
    cout << "    ";
    input--; 
  }
  cout << array[input2] << endl;
  if (leftposition <= count) {
    printree(array, count, current + 1, leftposition); 
  }
}
