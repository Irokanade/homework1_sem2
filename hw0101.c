//
//  hw0101.c
//  hw0101
//
//  Created by Michael Leong on 2021/3/4.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    char hex[256];
    unsigned long len = 0;
    char result[256] = {0};
    
    printf("Please enter the hex string: ");
    fgets(hex, 256, stdin);
    len = strlen(hex);
    
    while(((len-1)%2) != 0) {
        printf("hex input should have even number of characters as there might be non-printable ascii characters\n");
        printf("Please enter the hex string: ");
        fgets(hex, 256, stdin);
        len = strlen(hex);
    }
    
    for(char *i = hex; *i != 0; i++) {
        char hexTemp[3];
        char *endp;
        char tempChar[2];
        strncat(tempChar, i, 1);
        long intTemp = strtol(tempChar, &endp, 16);
        //printf("intTemp: %ld\n", intTemp);
        if(intTemp > 16 || intTemp < 0 || endp == NULL) {
            printf("Invalid hex conversion of: %c\n", *i);
            return 1;
        } else {
            if(strlen(hexTemp) != 2) {
                strncat(hexTemp, i, 1);
            } else {
                char ascLetter[2];
                long int ascInt = strtol(hexTemp, &endp, 16);
                //printf("ascInt: %ld\n", ascInt);
                if((ascInt!= 0) && (ascInt > 126 || ascInt < 32 || endp == NULL)) {
                    printf("Invalid ascii conversion of: %d\n", *i);
                    return 1;
                } else {
                    ascLetter[0] = (char)ascInt;
                }
                //printf("strtol: %ld\n", strtol(hexTemp, &endp, 16));
                //printf("ascLetter: %s\n", ascLetter);
                strncat(result, ascLetter, 1);
                memset(hexTemp, 0, 3);
                strncat(hexTemp, i, 1);
            }
        }
        
        //printf("ascTemp: %s\n", hexTemp);
        //printf("result: %s\n", result);
        memset(&tempChar, 0, 2);
    }
    
    printf("%s\n", result);
    
    return 0;
}
