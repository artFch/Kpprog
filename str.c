int scmp(char* s1, char* s2)
{
    if (s1 == NULL || s2 == NULL) {
        return -1;
    }
    for (int i = 0; s1[i] != '\0' || s2[i] != '\0'; i++) {
        if (s1[i] != s2[i]) {
            if (s1[i] > s2[i]) {
                return 1;
            } else if ((s1[i] < s2[i])) {
                return 2;
            }
        }
    }
	return 0;
}
