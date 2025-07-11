int myAtoi(char* s) {
    int i = 0;

    while (s[i] == ' ') {
        i++;
    }

    int sign = 1;
    if (s[i] == '-' || s[i] == '+') {
        sign = (s[i] == '-') ? -1 : 1;
        i++;
    }

    int res = 0;
    while (isdigit(s[i])) {
        int digit = s[i] - '0';
        if (res > INT_MAX / 10 || (res == INT_MAX / 10 && digit > INT_MAX % 10)) {
            return sign == 1 ? INT_MAX : INT_MIN;
        }
        res = res * 10 + digit;
        i++;
    }

    return res * sign;
}
