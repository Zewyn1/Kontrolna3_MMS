#include <stdio.h>
#include <stdlib.h>
#include <string.h>
     int read_int(FILE *f)
     {
         int i;
         fread(&i, sizeof(int), 1, f);
         return i;
     }
     void write_int(FILE *f, int i)
     {
         fwrite(&i, sizeof(int), 1, f);
     }

     int main() {
             FILE *f = fopen("test.bin", "rb");
         FILE *g = fopen("test.txt", "w");
         int i;
         while(!feof(f)) {
             i = read_int(f);
             fprintf(g, "%d\n", i);
         }
         fclose(f);
         fclose(g);
         return 0;
     }
