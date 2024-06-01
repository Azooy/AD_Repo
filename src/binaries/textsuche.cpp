#include "../lib/textsuche.h"

void printArray(char arr[], int n){
  for(int i = 0; i < n; i++){
    std::cout << arr[i];
  }
  std::cout << std::endl;
}

void fillArrayWithSubString(char arr[], char sub[], int n, int m, int index){
  for(int i = index; i > index+m; i--){
    arr[i] = sub[i-index];
  }
}

void clearArray(char arr[], int n){
  for(int i = 0; i < n; i++){
    arr[i] = ' ';
  }
}

int getIndex(char a){
  if(a == ' ') return 26;
  if(a == ',') return 27;
  return ((int)a-65);
}

/// @brief 
/// @param Text 
/// @param n 
/// @param Muster 
/// @param m 
/// @return 
int NaiveSearch(char Text[], int n, char Muster[], int m){
  int count = 0;
   int comps = 0;
  for(int i = 0; i <= n - m; i++){
    bool match = true;
    comps++;
    for(int j = 0; j < m; j++){
      if (Text[i+j] != Muster[j]){
        match = false;
        break;
      }
    }
    if(match) count++;
  }
  std::cout << "Comps: " << comps << std::endl;
  return count;
}


/// @brief 
/// @param Text 
/// @param n 
/// @param Muster 
/// @param m 
/// @return 
int NaiveSearch_improved(char Text[], int n, char Muster[], int m){
  int count = 0;
  int comps = 0;
  for(int i = 0; i <= n - m; i++){
    bool match = true;
    comps++;
    for(int j = 0; j < m; j++){
      if (Text[i+j] != Muster[j]){
        match = false;
        i+=j;
        break;
      }
    }
    if(match) count++;
  }
  std::cout << "Comps: " << comps << std::endl;
  return count;
}

int boyerMoore(char Text[], int n, char Muster[], int m){
  int j,i;
  int indexOverText;
  int indexOverMuster;
  int sizeofAlphabet = 28;
  int* shift = new int[sizeofAlphabet];
  char* checkString = new char[n];
  // fill the shifttable
  for(int i = 0; i < sizeofAlphabet; i++){ shift[i] = m;}
  for(int i = 0; i < m; i++){shift[getIndex(Muster[i])] = m-i-1;}
  int count = 0;
  j = i = m-1;
  for(int i = 0; i < n; i++){
    std::cout << Text[i];
  }
  while(i < n){
     if(Text[i] == Muster[j]){
      checkString[i] = Text[i];
      printArray(checkString, n);
      if(j == 0){
        // wenn Muster gefunden, inkrementiere den counter, schiebe komplett am Muster vorbei und setze normal-Zustand auf
        count++;
        i+=m;
        j=m-1;
      } else {
        // Travesiere durch das Muster und durch Text
        i--;
        j--;
      }
    }
    else { // Mismatch
      clearArray(checkString, n);
      
      if(m-j > shift[getIndex(Text[i])]){ // wenn die verbleibenden Zeichen des Muster mehr shiften würden als das Mismatch-Zeichen 
        i = i+m-j;
      }
      else{
        i = i+shift[getIndex(Text[i])]; // wenn das mismatch zeichen mehr verschieben würde
      }
      j = m-1; // setze zurück
    }
   
  }


  return count;
}