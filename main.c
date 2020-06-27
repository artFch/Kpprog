#include<stdio.h>
#include<stdlib.h>
#include"str.h"
#include"calcfreq.h"


void usage()
{
    printf("Usage:\n");
    printf("compress:   lzw -d -o text file.lzw\n");
    printf("decompress: lzw -d -o file.lzw text\n");
}

int open_files(const char* input_file, const char* output_file, FILE** in, FILE** out)
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


int main(int argc, char *argv[])
{
    if (argv[1] == NULL || argv[2] == NULL)
    {
        usage();
        return 1;
    }
    FILE*in;
    FILE*out;
    open_files(argv[1],argv[2],&in,&out);
    dictionary*dic = dic_init(65536);
    fill_dic(dic,in);
    printf("%d\n",dic->size);
    for (int i =0;i<dic->size;i++){
    printf("%s - %d\n",dic->str[i].s,dic->str[i].count);
    }
}






        
