# lib-secrete-bmp
Output BMP part by part for low memory or streaming applications (like MCUs)

## Origin
Original code came from a reply at [https://stackoverflow.com/questions/2654480/writing-bmp-image-in-pure-c-c-without-other-libraries/32027388](https://stackoverflow.com/questions/2654480/writing-bmp-image-in-pure-c-c-without-other-libraries/32027388)

I modified it to accept callback routines for part-by-part output.

## Usage

1. Copy libsecretebmp.c and .h to your project.
2. Use test.c as an example with its callbacks.

## Known issues

1. I don't compile to a lib currently.
