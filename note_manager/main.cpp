#include <iostream>
#include <string>


using namespace std;

// Gloabl Variables
const int INITIAL_CAPACITY {10};
string* notes {nullptr};
int note_count {0};
int capacity {INITIAL_CAPACITY};

void clearScreen();

void viewNotes();
void resizeNotes();
void addNote();
void deleteNote();


int main()
{
  notes = new string[capacity];

  int choice;

  do {
    clearScreen();
    cout << "\nNote Manager" << endl;
    cout << "1. View Notes" << endl;
    cout << "2. Add Note" << endl;
    cout << "3. Delete Note" << endl;
    cout << "4. Exit" << endl;
    cout << "Choose an option: ";
    cin >> choice;

    switch (choice)
    {
    case 1:
      viewNotes();
      break;
    case 2:
      addNote();
      break;
    case 3:
      deleteNote();
      break;
    case 4:
      cout << "Exiting the program " << endl;
      break;
    default:
      cout << "Invalid Choice" << endl;
      break;
    }

    if(choice !=4){
      char user_choice;
      cout << "\nDo you want to continue or exit? (y/n): ";
      cin >> user_choice;

      if(user_choice == 'n' || user_choice == 'N' || user_choice == '4'){
        choice = 4;
      }

    }

  } while (choice != 4);

  delete [] notes;
  return 0;
}

void viewNotes(){
  if(note_count == 0){
    cout << "No notes available." << endl;
    return;
  }

  for(int i {0}; i < note_count; i++){
    cout << (i+1) << " - " << notes[i] << endl;
  }
}


void clearScreen() {
    // Clear the terminal screen based on the operating system
#ifdef _WIN32
    system("CLS"); // For Windows
#else
    system("clear"); // For Unix/Linux/Mac
#endif
}

void resizeNotes(){
  capacity *= 2; // Duplicate capacity notes
  // Create new array of string with new capacity
  string* newNotes = new string[capacity];

  // copy the old notes to the newNotes pointers
  for(int i {0}; i < note_count; i++){
    newNotes[i] = notes[i];
  }

  delete [] notes; // Free memory old array
  notes = newNotes; // Update the notes pointer to point to the new array
}

void addNote(){
  if(note_count >= capacity){
    resizeNotes();
  }

  cout << "Add your note: ";
  cin.ignore(); // Clear any newline character left in the input buffer
  getline(cin, notes[note_count]);
  note_count++;
  cout << "Note added!" << endl;
}

void deleteNote(){
  if(note_count == 0){
    cout << "No notes available" << endl;
    return;
  }

  viewNotes(); // See the notes
  int note_index;
  cout << "Enter the number of the note to delete: ";
  cin >> note_index;

  if(note_index > 0 && note_index <= note_count){
    for(int i {note_index - 1}; i < note_count -1; i++){
      notes[i] = notes[i+1]; // Shif to left
    }
    note_count--;
    cout << "Note deleted" << endl;
  } else
  {
    cout << "Invalid Note Number" << endl;
  }
  
}