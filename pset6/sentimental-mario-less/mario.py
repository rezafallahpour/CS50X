import cs50
h = 0

while(h<2 or h>8):
    h = cs50.get_int("Height: ")

for i in range(h):
    print(" "*(h-(i+1)) + "#"*(i+1))