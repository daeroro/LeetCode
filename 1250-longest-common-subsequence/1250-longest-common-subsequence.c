/*
    abcde

    ace
*/
#define _MAX(a, b)  (((a) > (b)) ? (a) : (b))
int mem[1001][1001];

int longestCommonSubsequence(char* text1, char* text2) {
    int len1 = strlen(text1);
    int len2 = strlen(text2);

    for (int i=0; i<=len1; i++) {
        for (int j=0; j<=len2; j++) {
            mem[i][j] = 0;
        }
    }

    for (int j=len2-1; j>=0; j--) {
        for (int i=len1-1; i>=0; i--) {
            if (text1[i] == text2[j]) {
                mem[i][j] = 1 + mem[i+1][j+1];
            } else {
                mem[i][j] = _MAX(mem[i+1][j], mem[i][j+1]);
            }
        }
    }

    return mem[0][0];
}