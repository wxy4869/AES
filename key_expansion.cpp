#include <cstdio>
#include <cstdlib>
#include "cipher.h"
#include "xtime.h"

extern u_int8_t S_box[];

u_int8_t R[] = {0x02, 0x00, 0x00, 0x00};

u_int8_t * Rcon(int i) {
    if (i == 1) {
        R[0] = 0x01; // x^(1-1) = x^0 = 1
    } else {
        R[0] = 0x02;
        i--;
        while (i > 1) {
            R[0] = x2time(R[0]);
            i--;
        }
    }
    return R;
}

void SubWord(u_int8_t t[]) {
    for (int i = 0; i < 4; i++) {
        t[i] = S_box[t[i]];
    }
}

void RotWord(u_int8_t t[]) {
    /* 0  1  2  3  ->  1  2  3  0
     */
    u_int8_t tmp = t[0]; t[0] = t[1]; t[1] = t[2]; t[2] = t[3]; t[3] = tmp;
}

void KeyExpansion(const u_int8_t key[], u_int8_t w[]) {
    // 获得第 0 轮 4 个字
    for (int i = 0; i < 4 * Nk; i++) {
        w[i] = key[i];
    }

    // 获得第 1 轮到第 10 轮的字, 每轮 4 个字
    u_int8_t tmp[4];
    for (int i = Nk; i < Nb * (Nr + 1); i++) {
        // tmp 等于第 i - 1 个字
        for (int j = 0; j < 4; j++) {
            tmp[j] = w[j + (i - 1) * 4];  // 密钥第 i - 1 个字第 j 个字节
        }
        // 产生临时字
        if (i % Nk == 0) {
            RotWord(tmp);
            SubWord(tmp);
            Rcon(i / Nk);
            for (int j = 0; j < 4; j++) {
                tmp[j] ^= R[j];
            }
        } else if (Nk > 6 && i % Nk == 4) {
            SubWord(tmp);
        }
        // 第 i 个字 = 第 i - Nk 个字 ^ 临时字
        for (int j = 0; j < 4; j++) {
            w[j + i * 4] = w[j + (i - Nk) * 4] ^ tmp[j];
        }
    }
}

u_int8_t * MallocW(int key_length) {
    if (key_length == 128) {
        Nk = 4;
        Nr = 10;
    } else if (key_length == 192) {
        Nk = 6;
        Nr = 12;
    } else if (key_length == 256) {
        Nk = 8;
        Nr = 14;
    }
    return (u_int8_t * )malloc(Nb * (Nr + 1) * 4);
}
