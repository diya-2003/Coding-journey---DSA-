int minAddToMakeValid(char* s) {
    int balance = 0, count_close_needed = 0, i;
    for (i = 0; s[i] != '\0'; i++) {
        if (s[i] == '(')
            balance++;
        else 
            balance--;
        if (balance < 0) {
            count_close_needed++;
            balance = 0;
        }
    }
    return count_close_needed + balance;
}
