#include <stdio.h>



int length(char *S) {
    int len = 0;
    while (S && *S) {
        ++S;
        ++len;
    }
    return len;
}

int maximum(int a, int b) {
    if (a > b) {
        return a;
    }
    return b;
}


int getMaxMessageLength(char *S, int max_message_length) {
    printf("\nstring = %s\n", S);

    int i = 0;
    int len = length(S);
    while (i < len)
}

// Gets maximum message length starting at S
int getMaxMessageLength(char *S, int max_message_length) {
    printf("\nstring = %s\n", S);
    
    int max_so_far = 0;
    int current_count = 0;
    int len = length(S);
    if (len < max_message_length) return len;
    while (S && *S) {
        printf("%c", *S);
        if (*S == ' ') {
            max_so_far = maximum(max_so_far, current_count);
        }
        ++current_count;
        ++S;
    }
    printf("\nmsf = %d\n", max_so_far);
    
    return max_so_far;
}

int solution(char *S, int K) {
    // write your code in C99 (gcc 6.2.0)
    int msg_count = 0;
    int loc = 0;
    int end = length(S);
    while (S && (loc < end)) {

        int len = getMaxMessageLength(S + loc, K);
        printf("len = %d\n", len);
        ++msg_count;
        loc += len;
    }
    return msg_count;
    
}


int main() {

    // char a[] = "SMS messages are really short\0";
    char a[] = "SMSS are the best way to live life\0";
    int b = solution(a, 4);
    printf("%d\n", b);


    return 0;
}