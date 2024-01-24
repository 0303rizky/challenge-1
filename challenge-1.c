#include <stdio.h>
#include <stdlib.h>

void setup() {
  Serial.begin(9600);
}

void loop() {
  // Alokasikan memori di heap untuk menyimpan alfabet
  char *alphabet = (char *)malloc(27); // 26 karakter alfabet + 1 null terminator

  if (alphabet == NULL) {
    Serial.println("Gagal mengalokasikan memori.");
    return;
  }

  // Inisialisasi string dengan alfabet awal (a-z)
  for (int i = 0; i < 26; i++) {
    alphabet[i] = 'a' + i;
  }
  alphabet[26] = '\0'; // Menambahkan null terminator

  // Menampilkan string awal
  Serial.print("pola 1 ");
  Serial.println(alphabet);

  // Melakukan pergeseran alfabet sebanyak 10 kali
  for (int k = 0; k < 10; k++) {
    // Menampilkan string setelah pergeseran (mulai dari pengulangan kedua)
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

    // Menunggu sebentar 
    delay(1000); // Menunggu 1 detik
  }

  // Bebaskan memori yang telah dialokasikan di heap
  free(alphabet);

  // Loop tidak perlu dijalankan secara berulang pada Arduino IDE, sehingga tidak perlu mematikan perangkat.
}
