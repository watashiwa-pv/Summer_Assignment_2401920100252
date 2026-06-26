int romanToInt(char* s) {
    int alph[26]= {0}, result = 0;

    alph['I' - 'A'] = 1;
    alph['V' - 'A'] = 5;
    alph['X' - 'A'] = 10;
    alph['L' - 'A'] = 50;
    alph['C' - 'A'] = 100;
    alph['D' - 'A'] = 500;
    alph['M' - 'A'] = 1000;

    for (int i = 0; s[i]; i++) {
        if(s[i+1] && alph[s[i+1] - 'A'] > alph[s[i] - 'A'])
            result -= alph[s[i] - 'A'];
        else
            result += alph[s[i] - 'A'];
    }
    return result;
}
