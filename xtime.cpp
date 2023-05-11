#include <cstdio>

// 定义有限域 *2 乘法
u_int8_t x2time(u_int8_t x) {
    if (x & 0x80) {
        return (((x << 1) ^ 0x1B) & 0xFF);
    }
    return x << 1;
}

// 定义有限域 *3 乘法
u_int8_t x3time(u_int8_t x) {
    return (x2time(x) ^ x);
}

// 定义有限域 *4 乘法
u_int8_t x4time(u_int8_t x) {
    return (x2time(x2time(x)));
}

// 定义有限域 *8 乘法
u_int8_t x8time(u_int8_t x) {
    return (x2time(x2time(x2time(x))));
}

// 定义有限域 *9 乘法
u_int8_t x9time(u_int8_t x) {
    return (x8time(x) ^ x);
}

// 定义有限域 *B(11) 乘法
u_int8_t xBtime(u_int8_t x) {
    return (x8time(x) ^ x2time(x) ^ x);
}

// 定义有限域 *D(13) 乘法
u_int8_t xDtime(u_int8_t x) {
    return (x8time(x) ^ x4time(x) ^ x);
}

// 定义有限域 *E(15) 乘法
u_int8_t xEtime(u_int8_t x) {
    return (x8time(x) ^ x4time(x) ^ x2time(x));
}
