/*
    abcde

    ace
*/
#define _MAX(a, b)  (((a) > (b)) ? (a) : (b))
int mem[1001][1001];
char t1[1001];
char t2[1001];

int solve(int a, int b)
{
    if (mem[a][b] != -1)
        return mem[a][b];

    if (t1[a] == t2[b])
        return mem[a][b] = (1 + solve(a + 1, b + 1));
    else
        return mem[a][b] = _MAX(solve(a + 1, b), solve(a, b + 1));
}

int longestCommonSubsequence(char* text1, char* text2) {
    int len1 = strlen(text1);
    int len2 = strlen(text2);
    strcpy(t1, text1);
    strcpy(t2, text2);

    for (int i=0; i<len1; i++) {
        for (int j=0; j<len2; j++) {
            mem[i][j] = -1;
        }
    }
    for (int i=0; i<=len1; i++) mem[i][len2] = 0;
    for (int i=0; i<=len2; i++) mem[len1][i] = 0;

    return solve(0, 0);
}