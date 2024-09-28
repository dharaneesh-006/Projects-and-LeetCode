int romanToInt(char* s) {
    int r[256];
    r['I'] = 1;
    r['V'] = 5;
    r['X'] = 10;
    r['L'] = 50;
    r['C'] = 100;
    r['D'] = 500;
    r['M'] = 1000;

    int sum_val = 0;
    int size = strlen(s);
    int i = 0;

    while (i < size) {
        if (i < size - 1 && r[s[i]] < r[s[i + 1]]) {
            sum_val += r[s[i + 1]] - r[s[i]];
            i += 2;
        } else {
            sum_val += r[s[i]];
            i++;
        }
    }

    return sum_val;
}
