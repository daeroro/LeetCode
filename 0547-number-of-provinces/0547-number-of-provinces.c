int parent[201];

int getParent(int x)
{
    if (parent[x] == x)
        return x;
    parent[x] = getParent(parent[x]);
    return parent[x];
}

void update(int a, int b)
{
    int pa = getParent(a);
    int pb = getParent(b);

    parent[pa] = pb;
}

int findCircleNum(int** isConnected, int isConnectedSize, int* isConnectedColSize) {
    int ret = isConnectedSize;
    // init parent[]
    for (int i=0; i<isConnectedSize; i++)
        parent[i] = i;

    // iterate cities
        // iterate cities
    for (int i=0; i<isConnectedSize; i++) {
        for (int j=0; j<isConnectedSize; j++) {
            // is connect?
                // update parent[]
            if (isConnected[i][j] && getParent(i) != getParent(j)) {
                ret--;
                update(i, j);
            }
        }
    }

    // return
    return ret;
}