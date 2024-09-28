var romanToInt = function (s) {
    const r = {
        'I': 1,
        'V': 5,
        'X': 10,
        'L': 50,
        'C': 100,
        'D': 500,
        'M': 1000
    }
    let sum_val = 0
    let i = 0
    const size = s.length

    while (i < size) {
        if (i < size - 1 && r[s[i]] < r[s[i + 1]]) {
            sum_val += r[s[i + 1]] - r[s[i]]
            i += 2
        }
        else {
            sum_val += r[s[i]]
            i += 1
        }
    }
    return sum_val
};
