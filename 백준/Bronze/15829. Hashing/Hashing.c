#include <stdio.h>

unsigned long long Hashing(char* input, unsigned long long l){
    unsigned long long result = 0;
    unsigned long long r = 31;
    unsigned long long M = 1234567891;
    unsigned long long temp = 1;

    for (unsigned long long i = 0; i < l; i++) {
        unsigned long long char_value = ((int)input[i]) - 96; // a -> 1, b -> 2 ...
        result = (result + char_value * temp) % M; // 계산 중간에도 % M
        temp = (temp * r) % M; // r^i % M 계산
    }
    return result;
}

int main(void) {
    unsigned long long n;
    scanf("%llu", &n); // 입력 길이
    getchar(); // 버퍼 정리

    char input[51] = {0}; // 최대 길이 50 + NULL
    scanf("%s", input);   // 문자열 입력

    unsigned long long result = Hashing(input, n);
    printf("%llu\n", result);

    return 0;
}
