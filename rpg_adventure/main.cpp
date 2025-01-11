#include <iostream>
#include <vector>
#include <termios.h>
#include <unistd.h>
#include <thread>
#include <chrono>
#include <sys/select.h>

// Configura la modalità terminale per input non bloccante
void enableRawMode()
{
  termios term;
  tcgetattr(STDIN_FILENO, &term);          // Ottieni le impostazioni correnti
  term.c_lflag &= ~(ICANON | ECHO);        // Disabilita il buffering e l'eco del terminale
  tcsetattr(STDIN_FILENO, TCSANOW, &term); // Applica le modifiche
}

// Ripristina la modalità terminale
void disableRawMode()
{
  termios term;
  tcgetattr(STDIN_FILENO, &term);          // Ottieni le impostazioni correnti
  term.c_lflag |= (ICANON | ECHO);         // Riabilita il buffering e l'eco
  tcsetattr(STDIN_FILENO, TCSANOW, &term); // Applica le modifiche
}

// Funzione per leggere un carattere (non bloccante)
char getch()
{
  char buf = 0;
  read(STDIN_FILENO, &buf, 1);
  return buf;
}

// Funzione per controllare se c'è un input da tastiera
bool kbhit()
{
  struct timeval tv = {0, 0}; // Tempo zero per il controllo non bloccante
  fd_set fds;
  FD_ZERO(&fds);
  FD_SET(STDIN_FILENO, &fds);
  return select(STDIN_FILENO + 1, &fds, nullptr, nullptr, &tv) > 0;
}

// Funzione per simulare l'animazione del testo
void printTextWithDelay(const std::string &text, int delay_ms = 50)
{
  for (char c : text)
  {
    std::cout << c << std::flush;                                     // Stampa il carattere senza buffering
    std::this_thread::sleep_for(std::chrono::milliseconds(delay_ms)); // Ritardo tra i caratteri
  }
  std::cout << std::endl;
}

// Funzione per muovere il cursore
void moveCursor(int row, int col)
{
  std::cout << "\033[" << row << ";" << col << "H"; // Sposta il cursore alla riga/colonna specificata
}

// Funzione per cancellare lo schermo
void clearScreen()
{
  std::cout << "\033[2J\033[H"; // Clear screen e sposta il cursore all'inizio
}

int main()
{
  // Configura il terminale in modalità "raw"
  enableRawMode();
  atexit(disableRawMode); // Assicura il ripristino della modalità normale all'uscita

  // Simula l'animazione del testo
  std::string introText = "Benvenuto nel gioco!\nPremi Invio per vedere la mappa.";
  clearScreen();
  printTextWithDelay(introText, 100); // Simula la stampa del testo con un ritardo di 100 ms tra i caratteri

  // Aspetta che l'utente prema Invio
  while (true)
  {
    char key = getch();
    if (key == '\n')
    { // Se l'utente preme Invio, esci dal ciclo
      break;
    }
  }

  // Mappa (5x10 per esempio)
  std::vector<std::string> map = {
      "##########",
      "#        #",
      "#        #",
      "#        #",
      "##########"};

  int playerX = 1, playerY = 1; // Posizione iniziale del personaggio
  map[playerY][playerX] = 'P';
  clearScreen(); // Pulisce lo schermo prima di mostrare la mappa
  for (const auto &row : map)
  {
    std::cout << row << std::endl;
  }

  std::cout << std::flush; // Forza l'output immediato

  while (true)
  {
    // Attendi l'input dell'utente per i movimenti
    if (kbhit())
    {
      char key = getch(); // Legge il carattere premuto

      int newX = playerX;
      int newY = playerY;

      switch (key)
      {
      case 'w':
        newY--;
        break; // Su
      case 's':
        newY++;
        break; // Giù
      case 'a':
        newX--;
        break; // Sinistra
      case 'd':
        newX++;
        break; // Destra
      case 'q':
        return 0; // Esci dal gioco
      }

      // Controlla che il movimento sia valido
      if (map[newY][newX] == ' ')
      {
        // Svuota la posizione precedente
        map[playerY][playerX] = ' ';
        playerX = newX;
        playerY = newY;
        map[playerY][playerX] = 'P';

        // Sposta il cursore e aggiorna solo le righe interessate
        moveCursor(1, 1); // Sposta il cursore all'inizio del terminale
        for (const auto &row : map)
        {
          std::cout << row << std::endl;
        }

        std::cout << std::flush; // Forza l'output immediato
      }
    }

    // Piccolo ritardo per evitare consumo eccessivo di risorse
    std::this_thread::sleep_for(std::chrono::milliseconds(50));
  }

  return 0;
}
