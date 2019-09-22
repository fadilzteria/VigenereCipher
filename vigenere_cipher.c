#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char plaintext[250];
char key[250];
int length;

// Fungsi Vigenere Cipher
void vigenereCipher(){
	char ch, value;
	int i, keys;
	
	for(i = 0; plaintext[i] != '\0'; ++i){
		ch = plaintext[i];
		value = key[i%length];
		if(isalpha(value)) {
			if(isupper(value)) {
				keys = (int)(value) - 65;
			}
			else {
				keys = (int)(value) - 97;
			}
		}
		
		if(isalpha(ch)) {
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
	printf("Enter one sentence that you want to encrypt:\n");
	gets(plaintext);
	
	// mengambil input jumlah Key
	printf("Enter the key:\n");
	gets(key);
	length = strlen(key);
	
	// menjalankan fungsi caesarCipher
	vigenereCipher();
	
	printf("Hasil Enkripsi:\n");
	printf("%s\n", plaintext);
	
}
