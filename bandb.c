#ifndef __stdio_h_
#include <stdio.h>
#endif

#ifndef __string_h_
#include <string.h>
#endif

#ifndef __stdlib_h_
#include <stdlib.h>
#endif

// copies specified number of bytes from src to dest
// reverses byte copy order if reverse is true
void getbytes(unsigned char dest[], int bytes, void *src, int reverse){
    unsigned char *srcCpy = (unsigned char*)src;

    if (reverse == 0){
        for(int i = 0; i < bytes; i++){
            dest[i] = srcCpy[i];
        }
    }else{
        int j = 0;
        for(int i = bytes; i > 0; i--){
            dest[j] = srcCpy[i-1];
            j++;
        }
    }
}

// Converts bits in range start to end (from src) into the string dest
// Output is binary written as characters
void getbits(char dest[], int bytes, void *src, int start, int end){
    unsigned char *srcCpy = (unsigned char*)src;
    int div, rem, i = 0;
    char one = 1;
    char temp;

    while (start > end){
        div = start / 8;
        rem = start % 8;
        temp = (srcCpy[bytes - div - 1] & one << rem) >> rem;

        if (temp == 1){
            dest[i] = '1';
        }else{
            dest[i] = '0';
        }

        i++;
        start -= 1;
        one = 1;
    }
    dest[i] = '\0';
}

// Converts binary written in string form to an unsigned long long
unsigned long long bits2ull(char *bits){
    int i = 0, j = strlen(bits) - 1;
    unsigned long long output = 0;
    unsigned long long one = 1;

    while(i < strlen(bits)){
        if(bits[i] == '1'){
            output += (one << j);
        }
        i++;
        j--;
        one = 1;
    }

    return output;
}

// Converts binary written in string form to a signed long long
long long bits2ll(char *bits){
    int i = 0, j = strlen(bits) - 1;
    long long output = 0;
    long long one = 1;
    
    if(bits[0] == '1'){
        while(i < strlen(bits)){
            if(bits[i] == '0'){
                output += (one << j);
            }
            i++;
            j--;
            one = 1;
        }
        output += 1;
        output *= -1;
    }else{
        while(i < strlen(bits)){
            if(bits[i] == '1'){
                output += (one << j);
            }
            i++;
            j--;
            one = 1;
        }
    }
    
    return output;
}

// Converts a float into its binary form in a string
// The sign, exponent, and mentissa are split into three strings
void spff (char *sign, char *exponent, char *signigicand, float *src){
    char fullFloat[33];
    unsigned char orderedFloat[33];
    int j = 0;

    getbytes(orderedFloat, 4, src, 1);
    getbits(fullFloat, 4, orderedFloat, 31, -1);


    sign[0] = fullFloat[0];
    sign[1] = '\0';
    for(int i = 1; i < 9; i++){
        exponent[j] = fullFloat[i]; 
        j++;
    }
    exponent[8] = '\0';
    j = 0;
    for(int i = 9; i < 32; i++){
        signigicand[j] = fullFloat[i]; 
        j++;
    }
    signigicand[23] = '\0';
}

// Converts a double into its binary form in a string
// The sign, exponent, and mentissa are split into three strings
void dpff (char *sign, char *exponent, char *signigicand, double *src){
    char fullDouble[65];
    unsigned char orderedDouble[65];
    int j = 0;

    getbytes(orderedDouble, 8, src, 1);
    getbits(fullDouble, 8, orderedDouble, 63, -1);

    sign[0] = fullDouble[0];
    sign[1] = '\0';
    for(int i = 1; i < 12; i++){
        exponent[j] = fullDouble[i]; 
        j++;
    }
    exponent[11] = '\0';
    j = 0;
    for(int i = 12; i < 64; i++){
        signigicand[j] = fullDouble[i]; 
        j++;
    }
    signigicand[52] = '\0';
}
