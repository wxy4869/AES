#ifndef AES_CIPHER_H
#define AES_CIPHER_H
extern int Nb;
extern int Nk;
extern int Nr;
void Cipher(const u_int8_t in[], u_int8_t out[], u_int8_t w[]);
void AddRoundKey(u_int8_t state[], u_int8_t w[], int r);
#endif //AES_CIPHER_H
