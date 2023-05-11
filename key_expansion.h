#ifndef AES_KEY_EXPANSION_H
#define AES_KEY_EXPANSION_H
extern u_int8_t R[];
u_int8_t * Rcon(int i);
void KeyExpansion(const u_int8_t key[], u_int8_t w[]);
u_int8_t * MallocW(int key_length);
#endif //AES_KEY_EXPANSION_H
