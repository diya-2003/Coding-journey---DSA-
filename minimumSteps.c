long long minimumSteps(char* s) {
    long long c = 0, b = 0;
    for (register int i = 0; s[i] != '\0'; i++)
        if (s[i] == '0')
            c += b;
        else
            b++;
    return c;
}
