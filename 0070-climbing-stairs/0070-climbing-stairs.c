/*
    n = 1: output 1
    n = 2: output = 1 + 1 = 2
    n = 3: 1/1/1, 1/2, 2/1 = 3
    f(n) = f(n-1) + f(n-2) (n>=3)
    
*/
int mem[46];

int getSteps(int n)
{
    if (n == 1) return 1;
    else if (n == 2) return 2;
    else if (mem[n]) return mem[n];

    mem[n] = getSteps(n-1) + getSteps(n-2);
    return mem[n];
}

int climbStairs(int n) {
    for (int i=1; i<=n; i++)
        mem[i] = 0;
    
    return getSteps(n);
}