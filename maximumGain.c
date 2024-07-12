int maximumGain(char* s, int x, int y) {
    int res = 0;
    char top[3], bot[3];
    int top_score, bot_score;

    if (y > x) {
        strcpy(top, "ba");
        top_score = y;
        strcpy(bot, "ab");
        bot_score = x;
    } else {
        strcpy(top, "ab");
        top_score = x;
        strcpy(bot, "ba");
        bot_score = y;
    }

    // Removing first top substrings cause they give more points
    char stack[strlen(s) + 1];
    int stack_len = 0;
    for (int i = 0; s[i] != '\0'; i++) {
        char ch = s[i];  // Changed 'char' to 'ch'
        if (ch == top[1] && stack_len > 0 && stack[stack_len - 1] == top[0]) {
            res += top_score;
            stack_len--;
        } else {
            stack[stack_len++] = ch;
        }
    }

    // Removing bot substrings cause they give less or equal amount of scores
    char new_stack[strlen(s) + 1];
    int new_stack_len = 0;
    for (int i = 0; i < stack_len; i++) {
        char ch = stack[i];  // Changed 'char' to 'ch'
        if (ch == bot[1] && new_stack_len > 0 && new_stack[new_stack_len - 1] == bot[0]) {
            res += bot_score;
            new_stack_len--;
        } else {
            new_stack[new_stack_len++] = ch;
        }
    }

    return res;
}
