#from itertools import groupby
#result=[]
#n = int(input())
#g = list(map(int,input().split()))
#g.sort(reverse=True)
#count=1
#for i in range(0,len(g)):
#    if(g[i]==g[i+1]):
#        count=count+1
#    else:
#        break
#print(count)quit
#a=int(input())
#b=int(input())
#for i in range(100,999):
#    x=a%i
#    y=b%i
#    if(x==y):
#        res=i
#        break
#print(res)
#sum = 0 
#while (res != 0):
#    sum = int(sum + (res % 10)) 
#    res = int(res/10)  
#print(sum)
password="123"
def password_check(passwd): 
      
    SpecialSym =['$', '@', '#', '%'] 
    val = True
      
    if len(passwd) < 6: 
        print('length should be at least 6') 
        val = False
          
    if len(passwd) > 20: 
        print('length should be not be greater than 8') 
        val = False
          
    if not any(char.isdigit() for char in passwd): 
        print('Password should have at least one numeral') 
        val = False
          
    if not any(char.isupper() for char in passwd): 
        print('Password should have at least one uppercase letter') 
        val = False
          
    if not any(char.islower() for char in passwd): 
        print('Password should have at least one lowercase letter') 
        val = False
          
    if not any(char in SpecialSym for char in passwd): 
        print('Password should have at least one of the symbols $@#') 
        val = False
    if val: 
        return val
if (password_check(password)): 
        passwde=password
else: 
        password="x"
print(passwde)
        ###from django.core.exceptions import ObjectDoesNotExist
try:
  Model.objects.get(id=0)
  pass
except ObjectDoesNotExist:
  pass
