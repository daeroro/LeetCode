int parent[101];
int rank[101];

int _find(int x)
{
    if (x == parent[x])
        return x;
    
    parent[x] = _find(parent[x]);
    return parent[x];
}

void _union(int x, int y)
{
    int px = _find(x);
    int py = _find(y);

    if (rank[px] < rank[py]) {
        rank[px]++;
        parent[py] = px;
    } else if (rank[px] >= rank[py]) {
        rank[py]++;
        parent[px] = py;
    }
}

static int cmp(const void *a, const void *b)
{
    int *ap = *(int **)a;
    int *bp = *(int **)b;
    return (ap[0] - bp[0]); 
}

int earliestAcq(int** logs, int logsSize, int* logsColSize, int n) {
    // init parent, depth
    for (int i=0; i<n; i++) {
        parent[i] = i;
        rank[i] = 0;
    }
    int count = n;
    qsort(logs, logsSize, sizeof(int*), cmp);

    // iterate logs
    for (int i=0; i<logsSize; i++) {
        int x = logs[i][1];
        int y = logs[i][2];
        // if two people are not friend
        if (_find(x) != _find(y)) {
            // make them one group
            _union(x, y);
            // decrease the count
            // if count ==1
                // return timestamp
            count--;
            if (count == 1) {
                return logs[i][0];
            }
        }
    }
    // return -1
    return -1;
}