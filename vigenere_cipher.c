#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

char plaintext[250];
char key[250];
int length;
bool mode;

// Fungsi Vigenere Cipher
void vigenereCipher(bool dekrip){
	char ch, value;
	int i, keys, idx_key = 0;

	for(i = 0; plaintext[i] != '\0'; ++i){
        keys = 0;

		ch = plaintext[i];
		value = key[idx_key];
		if(isalpha(value)) {
			if(isupper(value)) {
				keys = (int)(value) - 65;
			}
			else {
				keys = (int)(value) - 97;
			}

            if(!dekrip){
                keys = 26 - keys;
            }
		}

		if(isalpha(ch)) {
            idx_key = (idx_key + 1)% length;
			if(isupper(ch)) {
				ch = (((int)(ch) + keys - 39) % 26 + 65); // 39 = 65 - 26
			}
			else {
				ch = (((int)(ch) + keys - 71) % 26 + 97); // 71 = 97 - 26
			}
		}

		plaintext[i] = ch;
	}

}

int main(){

	// mengambil input string
	printf("Enter one sentence that you want to encrypt/decrypt:\n");
	gets(plaintext);

	// mengambil input jumlah Key
	printf("Enter the key:\n");
	gets(key);
	length = strlen(key);

	// pilih mau enkrip atau dekrip
	printf("Enter 1 for Encrypt\nEnter 0 for Decrypt:\n");
	scanf("%d", &mode);


	// menjalankan fungsi caesarCipher
	vigenereCipher(mode);

	printf("Hasil Enkripsi:\n");
	printf("%s\n", plaintext);

}
