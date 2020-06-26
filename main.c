


void usage()
{
    printf("Usage:\n");
    printf("compress:   lzw -d -o text file.lzw\n");
    printf("decompress: lzw -d -o file.lzw text\n");
}

int main(int argc, char *argv[])
{

    if (argv[1] == NULL || argv[2] == NULL || argv[3] == NULL || argv[4] == NULL)
    {
        usage();
        return 1;





        int open_files(
        const char* input_file, const char* output_file, FILE** in, FILE** out)
{
    *in = fopen(input_file, "r");
    if (*in == NULL) {
        return -1;
    }
    *out = fopen(output_file, "r");
    if (*out != NULL) {
        printf("Wrong output file name\n");
        fclose(*out);
        fclose(*in);
        return -1;
    }
    *out = fopen(output_file, "w");
    if (*out == NULL) {
        fclose(*in);
        return -1;
    }
    return 0;
}
int sort_file(const char* input_file, const char* output_file, int sort_type)
{
    FILE *in, *out;

    int check = open_files(input_file, output_file, &in, &out);
    if (check == -1) {
        return -1;
    }

