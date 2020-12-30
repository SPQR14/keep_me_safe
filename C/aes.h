//
// Created by spqr14_ on 30/12/2020.
//

#ifndef KEEP_ME_SAFE_AES_H
#define KEEP_ME_SAFE_AES_H
void KeyExpansion(unsigned char key[], unsigned int w[], int keysize);
void aes_encrypt(unsigned char in[], unsigned char out[], unsigned int key[], int keysize);
void aes_decrypt(unsigned char in[], unsigned char out[], unsigned int key[], int keysize);
#endif //KEEP_ME_SAFE_AES_H
