long possiblePathsRecursive(int M, int N) {
    if (M==0 || N==0) {
        return 0;
    }

    if (M+N==2) {
        return 1;
    }

    return possiblePathsRecursive(M-1, N) + possiblePathsRecursive(M, N-1);
}

long possiblePathsIterative(int M, int N) {
    // homework
    unsigned long pathCount[N];
    // Set entire array to be 0 first to prevent weird binary addition, causing large signed values.
    for(int k = 0; k < N; k++)
    {
        pathCount[k] = 0;
    }

    // Set the first element to be 1.
    pathCount[0] = 1;

    // If either diam. is 0, return 0, as there is no possible path ever.
    if(M == 0 || N == 0)
    {
        return 0;
    }

    // If either diam. is 1, return 1, as there is only 1 possible path ever.
    if(M  == 1 || N == 1)
    {
        return 1;
    }

    // Calculating paths for each cell will be calculated from a left to right manner, going down each each row.
    for(int i = 0; i < M; i++)
    {
        for(int j = 1; j < N; j++)
        {
            pathCount[j] = pathCount[j] + pathCount[j - 1];
        }
    }
    return pathCount[N - 1];
}
