import numpy as np
import os
import subprocess
a=int(input("enter the numbers you want to do sort:-"))
print ("enter elements")
c=[]
c.append(a)
for i in range (0,a):
    b=int(input())
    
    c.append(b)

    
np.savetxt('array.csv', [c], delimiter=',', fmt='%d')
cmd = 'cd Desktop'
os.system(cmd)
print("located to desktop")

cmd = 'g++ nick.cpp -o a.exe'
os.system(cmd)
print("code compiled properly")

cmd = 'a.exe'
os.system(cmd)
print("code executed properly")
#out = subprocess.Popen(['wc', '-l', 'my.txt'], 
#           stdout=subprocess.PIPE, 
 #          stderr=subprocess.STDOUT)
#file1 = open("ex.txt","a")
#print (file1)
returned_text = subprocess.check_output("dir", shell=True, universal_newlines=True)
print("dir command to list file and directory")
print(returned_text)
f = open('ex.txt', 'r')
file_contents = f.read()
print (file_contents)
f.close()
