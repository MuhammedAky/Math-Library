#include <stdio.h>
#include <stdlib.h>

#include "../cmathematics/cmathematics.h"
#include "../cmathematics/data/encryption/aes.h"

char hex[16] = "0123456789ABCDEF";
void printCharArr(unsigned char *arr, int len, bool asChar)
{
    printf("{ ");
    for (int i = 0; i < len; i++)
    {
        printf("%c%c ", hex[arr[i] >> 4], hex[arr[i] & 0x0f]);
    }
    printf("}\n");
}

int main()
{
    printf("Hello, world!\n");

    int N = 27;
    unsigned char *txt = "asidlhgfyiuyguaysdgdcvetwee";
    unsigned char *key = "abcdefghijklmnop";
    unsigned char *iv = "zyxwvutsrqponmlk";
    unsigned char *cipher[3] = {NULL, NULL, NULL};
    unsigned char *dec[3] = {NULL, NULL, NULL};
    unsigned char *names[3] = {"AES-ECB", "AES-CBC", "AES-CTR"};

    for (int i = 0; i < 3; i++)
    {
        int encryptedLen = aes_encrypt(txt, N, key, AES_128, i, iv, cipher + i);
        int decryptedLen = aes_decrypt(cipher[i], encryptedLen, key, AES_128, i, iv, dec + i);

        printf("\n\n=================%s=================\n", names[i]);
        printf("Plaintext: ");
        printCharArr(txt, N, false);
        printf("Key:       ");
        printCharArr(key, 16, false);
        printf("Cipher:    ");
        printCharArr(cipher[i], encryptedLen, false);
        printf("Decrypted: ");
        printCharArr(dec[i], decryptedLen, false);

        free(cipher[i]);
        free(dec[i]);
    }

    // aes_mixCols(aes_inv_mixColMat); // gives identity matrix

    free(txt);
    free(key);
    free(iv);

    return 0;
}