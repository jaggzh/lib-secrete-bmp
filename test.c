#include <stdio.h>
#include <stdlib.h>

#include "libsecretebmp.h"

#define HEIGHT 261
#define WIDTH  367
unsigned char image[HEIGHT][WIDTH][BYTES_PER_PIXEL];
char* imageFileName = (char*) "bitmapImage.bmp";
FILE* imageFile;

unsigned char *callback_row(void *cbdata) {
	static int row=-1;
	row++;
	if (row >= HEIGHT) return NULL;
	return (char *)image[row];
}

void callback_writer(unsigned char *data, int size, int nmemb, void *cbdata) {
	fwrite(data, size, nmemb, imageFile);
}

void callback_done(void *cbdata) {
	fclose(imageFile);
}

int main () {
    int i, j;
    // Generate test gradient image data. Perdy.
    if (!(imageFile = fopen(imageFileName, "wb"))) {
    	fprintf(stderr, "Error fopen()ing file %s\n", imageFileName);
    	exit(1);
	}
    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
            image[i][j][2] = (unsigned char)(i * 255 / HEIGHT);             //red
            image[i][j][1] = (unsigned char)(j * 255 / WIDTH);              //green
            image[i][j][0] = (unsigned char)((i+j) * 255 / (HEIGHT+WIDTH)); //blue
        }
    }

    generateBitmapImageByRow(
    		&callback_row, &callback_writer, &callback_done, NULL,
    		HEIGHT, WIDTH);
    // fclose(imageFile); // done in callback for demonstration
    printf("Image generated!!\n");
}

