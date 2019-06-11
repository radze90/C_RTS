// Quellen: https://www.tutorials.de/threads/ziffern-einer-zahl-auslesen.316333/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

/**************************************************************
 * Schreiben Sie eine Funktion welche die Quersumme einer Zahl 
 * num berechnet Beispielsweise ist die Quersumme von "1234" 
 * gleich 10. Handelt es sich bei num nicht um eine Zahl 
 * gibt die Funktion -1 zurück.
 * Beispiel: sum_of_digits("not a number") == -1.
***************************************************************/
int sum_of_digits(char *num){
   // Testet, ob im String ein Buchstabe vorhanden ist
   int stringLaenge = strlen(num);
   int check;
   for(int i = 0; i < stringLaenge; i++){
      check = isdigit(*(num+i));
      if(check == 0)
         return -1;
   }
   
   int number = atoi(num);    // string to integer
   int temp, potenz = 10, ziffer, sum = 0;
   // Zahl in einzelne Ziffer zerlegen und Addieren (Quersumme)
   do {
      temp = number % potenz;             // Bsp.: 1234 % 10 = 4
      ziffer = (temp / (potenz / 10));    // Ziffer = 4 / (10 / 10)) = 4
      printf("%d\n", ziffer);
      potenz *= 10;                       // Potenz = 100
      number -= temp;                     // 1234 - 4
      sum += ziffer;
   } while (number != 0);
   return sum;
}

/**************************************************************
 * Schreiben Sie eine Funktion welche eine Zeile von dem 
 * Datenstrom f liest und zurückgibt und in len dessen Länge 
 * schreibt. Diese Funktion soll die POSIX Funktion getline() 
 * verwenden.
***************************************************************/
char *read_line(FILE *f, ssize_t *len){
   return 0;
}

/**************************************************************
 * Schreiben Sie eine Funktion welche eine Textdatei liest und 
 * ein Array zurückliefert, welche die Zeilen der Datei 
 * enthält, d.h. jeder Eintrag in dem Array enthält genau eine 
 * Zeile. Verwenden Sie zu implementation die Funktion 
 * read_line() aus dem vorherigen Aufgabenteil.
***************************************************************/
char **read_file(const char *filename){
   return 0;
}

/**************************************************************
 * Schreiben Sie ein Programm welche die Datei number.txt als 
 * Kommandozeilenparameter einliest, von jeder Zahl die 
 * Quersumme berechnet und am Ende die Summe aller Quersummen 
 * ausgibt. Das Programm soll die Funktion int sum_of_digits() 
 * aus dem Aufgabenteil a) und read_file() aus dem 
 * Aufgabenteil c) verwenden.
***************************************************************/
int main(){
   char *num_pt;
   char var[] = "1234567898";  // maximal 9 Zeichen, warum?
   int sum;

   num_pt = var;
   sum = sum_of_digits(num_pt);
   printf("Quersumme: %i\n", sum);

   return EXIT_SUCCESS;
}