#include <stdio.h>
int main()
{///�ɮ׫��� fout �}���ɮ�(�ɦW,write�Ҧ�)
    FILE * fout = fopen("file.txt" , "w+");
    printf(      "Hello World\n");
    fprintf(fout,"Hello World\n");
    fclose(fout);///�����ɮ�
}
