#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define M 101

char *hashTable[M];

int hash(char *key, int len){
    int r=0;

    for(int i=0; i<len; i++){
        r += (key[i] * (i+1))%M;
    }

}

int main () {

    int N, num, pos, count = 0;
    char string[30], command, *key;
    int flag;

    scanf("%d", &N);

    while(N--) {

        for(int i=0; i<N; i++){
            hashTable[i] = NULL; 
        }

        scanf("%d", &num);

        for(int i=0; i<N; i++){


            scanf("%s", string);
            key = &string[4];

            command = string[0];

            if(command == 'A') {

                flag = 1;

                for(int j=0; j<20; j++){
                    pos = (hash(key, len) + j*j +23*j)%M;

                    if(hashTable[pos] != NULL && strcomp(key, hashTable[pos]) == 0) {
                        flag = 0;
                        break;
                    }

                }

                if(flag) {
                    for(int j=0; j<20; j++) {
                        pos = (hash(key,len) + j*j + 23*j)%M;

                        if(hashTable[pos] == NULL) {
                            hashTable[pos] = malloc(sizeof(char) * (len+1));
                            strcpy(hashTable[pos], key);
                            count++;
                            break;
                        }
                    }
                }
            }
            else if(command == 'D') {
            for(int j=0; j<20; j++) {
                    pos = (hash(key,len) + j*j + 23*j)%M;

                    if(hashTable[pos] == NULL &&)strcmp(hashTable[pos], key)) {
                        free(hashTable[pos]);
                        hashTable[pos] = NULL;
                        count--:
                        break;
                    }
                }
            }

        }

         printf("%d\n", count);
            
            for(int i=0; i<M; i++){
                if(hashTable[i]!= NULL)
                    printf("%d:%s\n", i, hashTable[i]);
                }


        }
    }


}