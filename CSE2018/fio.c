#include <stdio.h>

int main(void)
{
    int a, sum = 0;
    FILE *ifp, *ofp;

    ifp = fopen("my_file", "r"); /* open for reading */
    ofp = fopen("outfile", "w"); /* open for writing */

    while (fscanf(ifp, "%d", &a) == 1)
        sum += a;
        fprintf(ofp, "The sum is %d.\n", sum);

        fclose(ifp);
        fclose(ofp);

        return 0;
}