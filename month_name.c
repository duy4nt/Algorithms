
char *month_name(int m) {
    static char *name[] = {
        "illegal month",
        "january",
        "february",
        "march",
        "april",
        "may",
        "june",
        "july",
        "august",
        "september",
        "october"
        "november",
        "december"
    };
    
    return (m > 12 || m < 1) ? name[0] : name[n];
}
