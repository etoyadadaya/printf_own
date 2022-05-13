//  sprintf.c

int s21_isdigit(int c) {
    if ((c < '0') || (c > '9'))
        return (0);
    return (1);
}

int	s21_isspace(int c) {
    return (c == ' ' || (c > 8 && c < 14));
}

int s21_len(long nb) {
    int len = 0;

    if (nb == 0) {
        len = 1;
    }
    if (nb < 0) {
        nb = nb * -1;
        len++;
    }
    while (nb > 0) {
        nb = nb / 10;
        len++;
    }
    return (len);
}

void s21_strreverse(char *str, int len) {
    int i = 0, j = len - 1, temp;

    while (i < j) {
        temp = (int)str[i];
        str[i] = str[j];
        str[j] = (char)temp;
        i++;
        j--;
    }
}

void s21_utoa(unsigned int num, char *str, int base) {
    int i = 0;

    if (num == 0) {
        str[i++] = 48;
        str[i] = 0;
        return;
    }

    while (num != 0) {
        int rem = num % base;
        str[i++] = (rem > 9) ? (rem - 10) + 97 : rem + 48;
        num = num / base;
    }

    str[i] = 0;

    s21_strreverse(str, (int)s21_strlen(str));
}

long long s21_pow(int x, unsigned n) {
    long long pow = 1;
    for (int i = 0; (unsigned int)i < n; i++) {
        pow = pow * x;
    }
    return pow;
}

char* s21_strdup(const char *s1) {
    size_t	i;
    char	*new;

    i = 0;
    new = NULL;
    if ((new = (char *)malloc(sizeof(const char *) * s21_strlen(s1) + 1))) {
        while (i < s21_strlen(s1)) {
            new[i] = s1[i];
            i++;
        }
        new[i] = 0;
    }
    return (new);
}

char* s21_strjoin(char const *s1, char const *s2) {
    size_t	i;
    size_t	i2;
    size_t	len1;
    size_t	len2;
    char	*new;

    i = 0;
    len1 = s21_strlen(s1);
    len2 = s21_strlen(s2);
    if (!(new = (char *)malloc(sizeof(char) * (len1 + len2) + 1))) {
        return (NULL);
    }
    while (i < len1) {
        new[i] = s1[i];
        i++;
    }
    i2 = 0;
    while (i < len1 + len2) {
        new[i] = s2[i2];
        i++;
        i2++;
    }
    new[i] = 0;
    return (new);
}

static int get_return(unsigned long long ret, int neg, const char *nptr) {
    int count = 0;
    while (*nptr <= 49 || *nptr >= 57)
        nptr++;
    while (s21_isdigit(*(nptr + count)))
        count++;
    if (count >= 19) {
        return (neg == -1 ? 0 : -1);
    }
    if (ret > 9223372036854775807) {
        return (neg == -1 ? 0 : -1);
    }
    else {
        return (int)(ret * neg);
    }
}

int s21_atoi(const char *nptr) {
    unsigned long long	ret;
    int len;
    int x;
    int neg;

    neg = 1;
    x = -1;
    len = 0;
    ret = 0;
    while (s21_isspace(*nptr))
        nptr++;
    while (nptr[len])
        len++;
    while (++x <= len) {
        if (s21_isdigit(nptr[x])) {
            ret = (ret * 10) + (nptr[x] - 48);
        }
        else if (x == 0 && (nptr[x] == 45 || nptr[x] == 43)) {
            neg = nptr[x] == 45 ? -1 : 1;
        }
        else {
            return (get_return(ret, neg, nptr));
        }
    }
    return (get_return(ret, neg, nptr));
}

void s21_ftoa(double f, char * buf, int precision) {
    char * ptr = buf;
    char * p = ptr;
    char * p1;
    char c;
    long intPart;

    if (f < 0) {
        f = -f;
        *ptr++ = 45;
    }

    if (precision < 0) {
        if (f < 1.0) precision = 6;
        else if (f < 10.0) precision = 5;
        else if (f < 100.0) precision = 4;
        else if (f < 1000.0) precision = 3;
        else if (f < 10000.0) precision = 2;
        else if (f < 100000.0) precision = 1;
        else precision = 0;
    }

    if (precision)
        f += 0.5 / (double)s21_pow(10, precision);

    intPart = (long)f;
    f -= intPart;

    if (!intPart) {
        *ptr++ = 48;
    }
    else {
        p = ptr;
        while (intPart) {
            *p++ = (char)(intPart % 10 + 48);
            intPart /= 10;
        }
        p1 = p;
        while (p > ptr) {
            c = *--p;
            *p = *ptr;
            *ptr++ = c;
        }
        ptr = p1;
    }
    if (precision) {
        *ptr++ = 46;
        while (precision--) {
            f *= 10.0;
            c = (char)f;
            *ptr++ = (char)(c + 48);
            f -= c;
        }
    }
    *ptr = 0;
}

char* s21_itoa(int n) {
    char *str;

    if (n == -2147483648) {
        return (s21_strdup("-2147483648"));
    }
    if (n < 0) {
        return (s21_strjoin("-", s21_itoa(-n)));
    }
    if (!(str = s21_strdup("0"))) {
        return (NULL);
    }
    *str = (char)(*str + (n % 10));
    if (n >= 0 && n <= 9) {
        return (s21_strdup(str));
    }
    else {
        return (s21_strjoin(s21_itoa(n / 10), str));
    }
}

int s21_atoi_base(const char *str, int base) {
    long nbr;
    unsigned long len;
    long i;

    len = s21_strlen(str);
    i = (long)len;
    nbr = 0;
    while (--i > 0 || (str[i] >= 97 && str[i] <= 122) || (str[i] >= 65 && str[i] <= 90) || (str[i] >= 48 && str[i] <= 57)) {
        if (str[i] >= 48 && str[i] <= 57) {
            nbr = nbr + (long)s21_pow(base, len - (i + 1)) * (str[i] - 48);
        }
        else if (str[i] >= 97 && str[i] <= 122) {
            nbr = nbr + (long)s21_pow(base, len - (i + 1)) * (str[i] - 97 + 10);
        }
        else if (str[i] >= 65 && str[i] <= 90) {
            nbr = nbr + (long)s21_pow(base, len - (i + 1)) * (str[i] - 65 + 10);
        }
    }
    return (nbr);
}

void s21_vsprintf(const char *format, va_list args) {
    int state = 0;
    int is_long = 0;
    int is_short = 0;
    int is_positive = 0;
    int is_negative = 0;
    int is_space = 0;
    int afterPoint = 0;
    int beforePoint = 0;

    while (*format) {
        if (state == 0) {
            if (*format == 37) {
                if (format[1] == 37) {
                    putchar(37);
                    format++;
                    state = 0;
                } else {
                    state = 1;
                }
            } else {
                putchar(*format);
            }
        }
        if (state == 1) {
            if (beforePoint == 0 && *format == 37) {
                char tmp[64] = "0";
                int j = 0;
                for (int i = 1; (unsigned int)i < s21_strlen(format); ++i) {
                    if (s21_isdigit(format[i])) {
                        tmp[j++] = format[i];
                        tmp[j] = 0;
                    } else {
                        beforePoint = s21_atoi(tmp);
                        break;
                    }
                }
            }
            if (afterPoint == 0 && *format == 46) {
                char tmp[64] = "0";
                int j = 0;
                for (int i = 1; (unsigned int)i < s21_strlen(format); ++i) {
                    if (s21_isdigit(format[i])) {
                        tmp[j++] = format[i];
                        tmp[j] = 0;
                    } else {
                        afterPoint = s21_atoi(tmp);
                        break;
                    }
                }
            }
            switch (*format) {
                case 'l': {
                    is_long = 1;
                    is_short = 0;
                    break;
                }
                case 'h': {
                    is_short = 1;
                    is_long = 0;
                    break;
                }
                case '+': {
                    is_positive = 1;
                    break;
                }
                case '-': {
                    is_negative = 1;
                    break;
                }
                case ' ': {
                    is_space = 1;
                    break;
                }
                case 'c': {
                    if (is_space) {
                        putchar(32);
                    }
                    char ch = va_arg(args, int);
                    if ((beforePoint - 1) > 0 && !is_negative) {
                        for (int i = beforePoint - 1; i > 0; i--) {
                            putchar(32);
                        }
                    }
                    putchar(ch);
                    if ((beforePoint - 1) > 0 && is_negative) {
                        for (int i = beforePoint - 1; i > 0; i--) {
                            putchar(32);
                        }
                    }
                    is_space = 0;
                    is_negative = 0;
                    beforePoint = 0;
                    state = 0;
                    break;
                }
                case 'd': {
                    if (is_space) {
                        putchar(32);
                    }
                    if (is_long) {
                        long d = va_arg(args, long);
                        char* buf;
                        buf = s21_itoa(d);
                        if ((beforePoint - s21_strlen(buf)) > 0 && !is_negative) {
                            for (int i = beforePoint - s21_strlen(buf); i > 0; i--) {
                                putchar(32);
                            }
                        }
                        if (is_positive && d > 0) {
                            putchar(43);
                        }
                        for (int i = 0; buf[i]; i++) {
                            putchar(buf[i]);
                        }
                        if ((beforePoint - s21_strlen(buf)) > 0 && is_negative) {
                            for (int i = beforePoint - s21_strlen(buf); i > 0; i--) {
                                putchar(32);
                            }
                        }
                    }
                    if (is_short) {
                        short d = va_arg(args, int);
                        char* buf;
                        buf = s21_itoa(d);
                        if ((beforePoint - s21_strlen(buf)) > 0 && !is_negative) {
                            for (int i = beforePoint - s21_strlen(buf); i > 0; i--) {
                                putchar(32);
                            }
                        }
                        if (is_positive && d > 0) {
                            putchar(43);
                        }
                        for (int i = 0; buf[i]; i++) {
                            putchar(buf[i]);
                        }
                        if ((beforePoint - s21_strlen(buf)) > 0 && is_negative) {
                            for (int i = beforePoint - s21_strlen(buf); i > 0; i--) {
                                putchar(32);
                            }
                        }
                    }
                    if (!is_short && !is_long) {
                        long int d = va_arg(args, int);
                        char* buf;
                        buf = s21_itoa(d);
                        if ((beforePoint - s21_strlen(buf)) > 0 && !is_negative) {
                            for (int i = beforePoint - s21_strlen(buf); i > 0; i--) {
                                putchar(32);
                            }
                        }
                        if (is_positive && d > 0) {
                            putchar(43);
                        }
                        for (int i = 0; buf[i]; i++) {
                            putchar(buf[i]);
                        }
                        if ((beforePoint - s21_strlen(buf)) > 0 && is_negative) {
                            for (int i = beforePoint - s21_strlen(buf); i > 0; i--) {
                                putchar(32);
                            }
                        }
                    }
                    is_space = 0;
                    is_negative = 0;
                    beforePoint = 0;
                    is_positive = 0;
                    is_short = 0;
                    is_long = 0;
                    state = 0;
                    break;
                }
                case 'i': {
                    if (is_space) {
                        putchar(32);
                    }
                    int d = va_arg(args, int);
                    if ((beforePoint - s21_len(d)) > 0 && !is_negative) {
                        for (int i = beforePoint - s21_len(d); i > 0; i--) {
                            putchar(32);
                        }
                    }
                    if (is_positive && d > 0) {
                        putchar(43);
                    }
                    char* buf;
                    if (buf[0] != 0) {
                        buf = s21_itoa(s21_atoi_base(s21_itoa(d), 10));
                        for (int i = 0; buf[i]; i++) {
                            putchar(buf[i]);
                        }
                    } else if (buf[0] == 0 && buf[1] == 120) {
                        buf = s21_itoa(s21_atoi_base(s21_itoa(d), 16));
                        for (int i = 0; buf[i]; i++) {
                            putchar(buf[i]);
                        }
                    } else if (buf[0] == 0 && buf[1] != 120) {
                        buf = s21_itoa(s21_atoi_base(s21_itoa(d), 8));
                        for (int i = 0; buf[i]; i++) {
                            putchar(buf[i]);
                        }
                    }
                    if ((beforePoint - s21_len(d)) > 0 && is_negative) {
                        for (int i = beforePoint - s21_len(d); i > 0; i--) {
                            putchar(32);
                        }
                    }
                    is_space = 0;
                    is_negative = 0;
                    beforePoint = 0;
                    is_positive = 0;
                    state = 0;
                    break;
                }
                case 'f': {
                    if (is_space) {
                        putchar(32);
                    }
                    double f = va_arg(args, double);
                    char buf[32];
                    if (afterPoint == 0) {
                        s21_ftoa(f, buf, 6);
                    } else {
                        s21_ftoa(f, buf, afterPoint);
                    }
                    if ((beforePoint - s21_strlen(buf)) > 0 && !is_negative) {
                        for (int i = beforePoint - s21_strlen(buf); i > 0; i--) {
                            putchar(32);
                        }
                    }
                    if (is_positive && f > 0) {
                        putchar(43);
                    }
                    for (int i = 0; buf[i]; i++) {
                        putchar(buf[i]);
                    }
                    if ((beforePoint - s21_strlen(buf)) > 0 && is_negative) {
                        for (int i = beforePoint - s21_strlen(buf); i > 0; i--) {
                            putchar(32);
                        }
                    }
                    is_space = 0;
                    is_negative = 0;
                    beforePoint = 0;
                    is_positive = 0;
                    afterPoint = 0;
                    state = 0;
                    break;
                }
                case 's': {
                    if (is_space) {
                        putchar(32);
                    }
                    const char *s = va_arg(args, const char*);
                    s21_size_t len = s21_strlen(s);
                    if ((beforePoint - len) > 0 && !is_negative) {
                        for (int i = beforePoint - len; i > 0; i--) {
                            putchar(32);
                        }
                    }
                    while (*s) {
                        putchar(*s++);
                    }
                    if ((beforePoint - len) > 0 && is_negative) {
                        for (int i = beforePoint - len; i > 0; i--) {
                            putchar(32);
                        }
                    }
                    is_space = 0;
                    is_negative = 0;
                    beforePoint = 0;
                    state = 0;
                    break;
                }
                case 'u': {
                    if (is_space) {
                        putchar(32);
                    }
                    if (is_long) {
                        unsigned long u = va_arg(args, long);
                        char buf[32];
                        s21_utoa(u, buf, 10);
                        if ((beforePoint - s21_strlen(buf)) > 0 && !is_negative) {
                            for (int i = beforePoint - s21_strlen(buf); i > 0; i--) {
                                putchar(32);
                            }
                        }
                        if (is_positive && u > 0) {
                            putchar(43);
                        }
                        for (int i = 0; buf[i]; i++) {
                            putchar(buf[i]);
                        }
                        if (afterPoint) {
                            putchar(48);
                        }
                        if ((beforePoint - s21_strlen(buf)) > 0 && is_negative) {
                            for (int i = beforePoint - s21_strlen(buf); i > 0; i--) {
                                putchar(32);
                            }
                        }
                    }
                    if (is_short) {
                        unsigned short u = va_arg(args, int);
                        char buf[32];
                        s21_utoa(u, buf, 10);
                        for (int i = 0; buf[i]; i++) {
                            putchar(buf[i]);
                        }
                        if ((beforePoint - s21_strlen(buf)) > 0 && !is_negative) {
                            for (int i = beforePoint - s21_strlen(buf); i > 0; i--) {
                                putchar(32);
                            }
                        }
                        if (is_positive && u > 0) {
                            putchar(43);
                        }
                        if (afterPoint) {
                            putchar(48);
                        }
                        if ((beforePoint - s21_strlen(buf)) > 0 && is_negative) {
                            for (int i = beforePoint - s21_strlen(buf); i > 0; i--) {
                                putchar(32);
                            }
                        }
                    }
                    if (!is_short && !is_long) {
                        unsigned int u = va_arg(args, unsigned int);
                        char buf[32];
                        s21_utoa(u, buf, 10);
                        if ((beforePoint - s21_strlen(buf)) > 0 && !is_negative) {
                            for (int i = beforePoint - s21_strlen(buf); i > 0; i--) {
                                putchar(32);
                            }
                        }
                        if (is_positive && u > 0) {
                            putchar(43);
                        }
                        for (int i = 0; buf[i]; i++) {
                            putchar(buf[i]);
                        }
                        if (afterPoint) {
                            putchar(48);
                        }
                        if ((beforePoint - s21_strlen(buf)) > 0 && is_negative) {
                            for (int i = beforePoint - s21_strlen(buf); i > 0; i--) {
                                putchar(32);
                            }
                        }
                    }
                    is_space = 0;
                    is_negative = 0;
                    beforePoint = 0;
                    is_positive = 0;
                    is_short = 0;
                    is_long = 0;
                    state = 0;
                    break;
                }
            }
        }
        format++;
    }
}

int s21_sprintf(const char *format, ...) {
    va_list args;
    va_start(args, format);
    s21_vsprintf(format, args);
    va_end(args);
    return 0;
}