#!/bin/bash

echo -n -e \\x00\\x00\\x03\\xe8 > thousand.bin
echo -n -e \\x00\\x00\\x01\\xf4 > five-hundred.bin
./add-nbo thousand.bin five-hundred.bin

rm thousand.bin
rm five-hundred.bin
