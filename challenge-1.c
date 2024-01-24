#include <stdio.h>
#include <stdlib.h>

void setup() {
  Serial.begin(9600);
}

void loop() {
  char *alphabet = (char *)malloc(27); 
  if (alphabet == NULL) {
    Serial.println("Gagal mengalokasikan memori.");
    return;
  }

  for (int i = 0; i < 26; i++) {
    alphabet[i] = 'a' + i;
  }
  alphabet[26] = '\0'; 


  Serial.print("pola 1 ");
  Serial.println(alphabet);

  for (int k = 0; k < 10; k++) {
  
    if (k > 0) {
      Serial.print("pola ");
      Serial.print(k+1);
      Serial.print(": ");
      Serial.println(alphabet);
    }

    if (k < 10) {
      char first_char = alphabet[0];

      for (int i = 0; i < 25; i++) {
        alphabet[i] = alphabet[i + 1];
      }

      alphabet[25] = first_char;
    }

    delay(1000); 
  }

 
  free(alphabet);


}
