const char *simple[] = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};
const char *secondary[] = {"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
const char *teens[] = {"Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};

void three(int num, char *result) {
    bool first = true;

    if (num >= 100) {
        if (!first) {
            strcat(result, " ");
        }
        strcat(result, simple[num / 100]);
        strcat(result, " Hundred");
        num %= 100;
        first = false;
    }
    if (num >= 20) {
        if (!first) {
            strcat(result, " ");
        }
        strcat(result, secondary[num / 10]);
        num %= 10;
        first = false;
    } else if (num >= 10) {
        if (!first) {
            strcat(result, " ");
        }
        strcat(result, teens[num - 10]);
        num = 0;
        first = false;
    }

    if (num > 0) {
        if (!first) {
            strcat(result, " ");
        }
        strcat(result, simple[num]);
        num %= 20;
        first = false;
    }
}

char* numberToWords(int num) {
    char *result = malloc(1000 * sizeof(char));
    bool first = true;

    *result = '\0';

    if (num >= 1000000000) {
        if (!first) {
            strcat(result, " ");
        }
        three(num / 1000000000, result);
        strcat(result, " Billion");
        num %= 1000000000;
        first = false;
    }
    if (num >= 1000000) {
        if (!first) {
            strcat(result, " ");
        }
        three(num / 1000000, result);
        strcat(result, " Million");
        num %= 1000000;
        first = false;
    }
    if (num >= 1000) {
        if (!first) {
            strcat(result, " ");
        }
        three(num / 1000, result);
        strcat(result, " Thousand");
        num %= 1000;
        first = false;
    }
    if (num > 0) {
        if (!first) {
            strcat(result, " ");
        }
        three(num, result);
        num = 0;
        first = false;
    }

    if (first) {
        strcat(result, "Zero");
    }
    
    return result;
}
