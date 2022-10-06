Follow a patern of writing, keeping the code clean and without memory leaks. Always run with leaks.
Start moving the character. Work a bit about the initial map checker. There is some problem with reading
the position 0 0. It shows the wrong given values. It is somehow related to position [1][0] and [0][1].
From the map.ber we only read, rewrite everything to the read write file and then operate on that file descriptor.
Working on getting the map directly to the read and write function.
Use a cross mask to check for path. 

6102022 Create the array from the given map first. Afterwards operate on it then render the image.
