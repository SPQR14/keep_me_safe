/*
 ** Created by spqr14_ on 30/12/2020.
 ** Copyright: GNU GPL 3.0
 ** Advanced Encryption Standard
 ** This code is the implementation of the AES algorithm, as specified by the NIST in publication FIPS PUB 197, available on the NIST website at
 ** http://csrc.nist.gov/publications/fips/fips197/fips-197.pdf
 */

#include <stdio.h>
#include "aes.h"

/*
Output should be:
00112233445566778899aabbccddeeff
8ea2b7ca516745bfeafc49904b496089
00000000000000000000000000000000
4bf3b0a69aeb6657794f2901b1440ad4
*/

int main(){
    // This is one set of test vectors. Plaintext1 should encrypt to ciphertext1 using
    // key1 and the ciphertext1 should decrypt to the plaintext1 using key1.
    unsigned char plaintext[16]={0x00,0x11,0x22,0x33,0x44,0x55,0x66,0x77,
                                 0x88,0x99,0xaa,0xbb,0xcc,0xdd,0xee,0xff};
    unsigned char ciphertext[16]={0x8e,0xa2,0xb7,0xca,0x51,0x67,0x45,0xbf,
                                  0xea,0xfc,0x49,0x90,0x4b,0x49,0x60,0x89};
    unsigned char key[32]={0x00,0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08,
                           0x09,0x0a,0x0b,0x0c,0x0d,0x0e,0x0f,0x10,0x11,
                           0x12,0x13,0x14,0x15,0x16,0x17,0x18,0x19,0x1a,
                           0x1b,0x1c,0x1d,0x1e,0x1f};
    // Another set of test vectors. Plaintext2 should encrypt to ciphertext2 using key2,
    // and ciphertext2 should decrypt to plaintext2 using key2.
    unsigned char plaintext2[16]={0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
                                  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00};
    unsigned char ciphertext2[16]={0x4b,0xf3,0xb0,0xa6,0x9a,0xeb,0x66,0x57,
                                   0x79,0x4f,0x29,0x01,0xb1,0x44,0x0a,0xd4};
    unsigned char key2[32]={0x28,0xd4,0x6c,0xff,0xa1,0x58,0x53,0x31,
                            0x94,0x21,0x4a,0x91,0xe7,0x12,0xfc,0x2b,
                            0x45,0xb5,0x18,0x07,0x66,0x75,0xaf,0xfd,
                            0x91,0x0e,0xde,0xca,0x5f,0x41,0xac,0x64};
    unsigned int key_schedule[60],idx;

    // First set of test vectors.
    KeyExpansion(key,key_schedule,256);

    printf("Plaintext: ");
    for (idx=0; idx < 16; idx++)
        printf("%02x",plaintext[idx]);
    puts("");
    printf("Ciphertext: ");
    aes_encrypt(plaintext,ciphertext,key_schedule,256);
    for (idx=0; idx < 16; idx++)
        printf("%02x",ciphertext[idx]);
    puts("");
    aes_decrypt(ciphertext,plaintext,key_schedule,256);
    printf("Decripted Plaintext: ");
    for (idx=0; idx < 16; idx++)
        printf("%02x",plaintext[idx]);
    printf("\n");

    // Second set of test vectors.
    printf("Plaintext 2: ");
    for (idx=0; idx < 16; idx++)
        printf("%02x",plaintext2[idx]);
    printf("\n");
    KeyExpansion(key2,key_schedule,256);
    aes_encrypt(plaintext2,ciphertext2,key_schedule,256);
    printf("Ciphertext 2: ");
    for (idx=0; idx < 16; idx++)
        printf("%02x",ciphertext2[idx]);
    puts("");
    aes_decrypt(ciphertext2,plaintext2,key_schedule,256);
    printf("Decripted Plaintext 2: ");
    for (idx=0; idx < 16; idx++)
        printf("%02x",plaintext2[idx]);
    printf("\n");


    return 0;
}

