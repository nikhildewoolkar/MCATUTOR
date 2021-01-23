from django.shortcuts import render,redirect
from django.http import HttpResponse
from .models import SignUp,Faculty,Slider,achieve,homepics
from .models import alumni,Library_vlink,Library_pdf,newsletter
from .models import UserProfile,Profile,PrivateSetting,FileUpload
from django.contrib.auth.models import User , auth
from .models import Feedback,TutorContent
from django.contrib import messages
from django.contrib.auth.forms import PasswordChangeForm
from django.contrib.auth import update_session_auth_hash
from django.core.exceptions import ObjectDoesNotExist
import datetime
import os
import numpy as np
from subprocess import check_output, CalledProcessError,STDOUT
# Create your views here.

def home(request):
    pics=Slider.objects.all()
    # for p in pics:
    #     print(p.index)
    photos=homepics.objects.all()
    return render(request,"home.html",{'pics':pics,'photos':photos})
def faculties(request):
    fac=Faculty.objects.all()
    pics=Slider.objects.all()
    return render(request,"faculties.html",{'fac':fac,'pics':pics})
def contact(request):
    pics=Slider.objects.all()
    return render(request,"contact.html",{'pics':pics})
def library(request):
    pics=Slider.objects.all()
    pdf=Library_pdf.objects.all()
    vlink=Library_vlink.objects.all()
    if request.method=='POST':
        id=int(request.POST.get("id"))
        return render(request,"library.html",{'pics':pics,"id":id,'pdf':pdf,'vlink':vlink})
    else:
        id=0
        return render(request,"library.html",{'pics':pics,"id":id})
def students(request):
    pics=Slider.objects.all()
    year=achieve.objects.all()
    test=alumni.objects.all()
    if request.method=='POST':
        id=int(request.POST.get("id"))
        return render(request,"students.html",{'pics':pics,"id":id,'year':year,'test':test})
    else:
        id=0
        return render(request,"students.html",{'pics':pics,"id":id})
def tutor(request):
    pics=Slider.objects.all()
    t=TutorContent.objects.all()
    if request.method=='POST':
        id=int(request.POST.get("id"))
        return render(request,"tutor.html",{'pics':pics,"id":id,'t':t})
    else:
        id=0
        return render(request,"tutor.html",{'pics':pics,"id":id})
def signup(request):
    pics=Slider.objects.all()
    if request.method=='POST':
        first_name=request.POST.get("fname")
        last_name=request.POST.get("lname")
        username = request.POST.get("uid")
        email=request.POST.get("email")
        password=request.POST.get("pass")
        password1=request.POST.get("pass1")
        def password_check(password):
            SpecialSym =['$', '@', '#', '%'] 
            val = True
            if len(password) < 8:
                print('length should be at least 6') 
                val = False
            if len(password) > 20: 
                print('length should be not be greater than 8') 
                val = False
            if not any(char.isdigit() for char in password): 
                print('Password should have at least one numeral') 
                val = False
            if not any(char.isupper() for char in password): 
                print('Password should have at least one uppercase letter') 
                val = False
            if not any(char.islower() for char in password): 
                print('Password should have at least one lowercase letter') 
                val = False
            if not any(char in SpecialSym for char in password): 
                print('Password should have at least one of the symbols $@#') 
                val = False
            if val == False: 
                val=True
                return val
                print(val)
        if (password_check(password)): 
            print("y")
        else: 
            print("x")
        #print(password)                    
        if password==password1:
            if User.objects.filter(username=username).exists():
                messages.info(request,'Username taken')
                return redirect('signup')
            elif User.objects.filter(email=email).exists():
                messages.info(request,'email taken')
                return redirect('signup')
            elif (password_check(password)):
                messages.info(request,'password is not valid')
                print("harshad")
                return redirect('signup')
            else:
                user=User.objects.create_user(username=username,password=password,email=email,first_name=first_name,last_name=last_name)
                user.save()
                work=SignUp(username=username,password=password,email=email,first_name=first_name,last_name=last_name,profilepic="nikhil.jpg",year="none",batch="none",privateemail="none",phoneno="none",address="none",description="none",skillset="none",github="none",hackerrank="none",codechef="none",private="no")
                work.save()
                messages.info(request,"user created succesfully")
                #user=auth.authenticate(username=username,password=password)
                #if user is not None:
                #    auth.login(request,user)
                #print("nikhil")
                #u = User.objects.get(username=username)
                #reg=UserProfile(user=u,usernames=username,year="none",batch="none",privateemail="none",phoneno="none",address="none",description="none",skillset="none",github="none",hackerrank="none",codechef="none")
                #reg.save()
                #print("dewoolkar")
                #auth.logout(request)
                #print("nitin")
        else:
            messages.info(request,"password not matching")
            return redirect('signup')
        return redirect('login')
    return render(request,"signup.html",{'pics':pics})

def login(request):
    email=newsletter.objects.all()
    pics=Slider.objects.all()
    if request.method=="POST":
        username=request.POST.get("username")
        password=request.POST.get("pwd")
        print(username)
        print(password)
        user=auth.authenticate(username=username,password=password)
        if user is not None:
            auth.login(request,user)
            return redirect('/')
        else:
            messages.info(request,"Invalid Credentials")
            return redirect('login')
    return render(request,"login.html",{'pics':pics,'email':email})
def portal(request):
    pics=Slider.objects.all()
    n=FileUpload.objects.all()
    if request.method=="POST":
        id=int(request.POST.get("id"))
        return render(request,"portal.html",{'pics':pics,"id":id,'n':n})
    else:
        id=0
        return render(request,"portal.html",{'pics':pics,"id":id})

    return render(request,"portal.html",{'pics':pics})
def logout(request):
    auth.logout(request)
    photos=homepics.objects.all()
    pics=Slider.objects.all()
    return render(request,"home.html",{'pics':pics,'photos':photos})
def news(request):
    pics=Slider.objects.all()
    newsl=newsletter.objects.all()
    if request.method=="POST":
        emailid=request.POST.get("emailid")
        register=newsletter(email=emailid)
        register.save()
    return render(request,"home.html",{'pics':pics})
    #return redirect("/")
def fb(request):
    nikhil=Feedback.objects.all()
    pics=Slider.objects.all()
    if request.method=="POST":
        print("motherfucker")
        name=request.POST.get("name")
        email=request.POST.get("email")
        sub=request.POST.get("sub")
        msg=request.POST.get("msg")
        register=Feedback(name=name ,email=email ,subject=sub ,msg=msg)
        register.save()
    return render(request,"contact.html",{'pics':pics})

def profile(request):
    pics=Slider.objects.all()
    n=FileUpload.objects.all()
    if request.method=="POST":
        id=int(request.POST.get("id"))
        return render(request,"profile.html",{'pics':pics,"id":id,'n':n})
    else:
        id=0
        return render(request,"profile.html",{'pics':pics,"id":id})

def editprofile(request):
    pics=Slider.objects.all()
    id=0
    if request.method=="POST":
        print("motherfucker")
        username=request.POST.get("username")
        usernames=request.POST.get("u")
        print(request.POST.get("u"))
        print(username)     
        print(usernames)
        year=request.POST.get("year")
        batch=request.POST.get("batch")
        pemail=request.POST.get("pemail")
        phoneno=request.POST.get("phoneno")
        address=request.POST.get("address")
        des=request.POST.get("des")
        skill=request.POST.get("skill")
        github=request.POST.get("github")
        hackerrank=request.POST.get("hackerrank")
        codechef=request.POST.get("codechef")
        print(codechef)
        #print({{User.userprofile.codechef}})
        #user=User.objects.get(username=username)
        #codechef=user.userprofile.codechef
        #User.userprofile(codechef=codechef)
        #User.save()
        #user.userprofile.codechef=codechef
        #user.save()
        #u = User.objects.get(username=username)
        #p1=request.user
        #print(p1.email)
        #p2=UserProfile.objects.get(usernames=p1.username)
        #p2=p1.UserProfile.objects.all()
        #userprofile = UserProfile.objects.get(user = user)
        if(usernames==""):
            print("nikhil")
            u = User.objects.get(username=username)
            reg=UserProfile(user=u,usernames=username,year=year,batch=batch,privateemail=pemail,phoneno=phoneno,address=address,description=des,skillset=skill,github=github,hackerrank=hackerrank,codechef=codechef)
            SignUp.objects.filter(username=username).update(year=year,batch=batch,privateemail=pemail,phoneno=phoneno,address=address,description=des,skillset=skill,github=github,hackerrank=hackerrank,codechef=codechef)
            reg.save()
        else:
            print("chutiya")
            u = User.objects.get(username=username)
            print(u.id)
            UserProfile.objects.filter(usernames=username).update(usernames=username,year=year,batch=batch,privateemail=pemail,phoneno=phoneno,address=address,description=des,skillset=skill,github=github,hackerrank=hackerrank,codechef=codechef)
            SignUp.objects.filter(username=username).update(year=year,batch=batch,privateemail=pemail,phoneno=phoneno,address=address,description=des,skillset=skill,github=github,hackerrank=hackerrank,codechef=codechef)
            print(username)
            print(usernames)
        return render(request,"profile.html",{'pics':pics,"id":id})
    return render(request,"profile.html",{'pics':pics,"id":id})

def ProfilePic(request):
    pics=Slider.objects.all()
    id=0
    if request.method=="POST":
        usernames=request.POST.get("u")
        print(usernames)
        dp = request.FILES.get("image_dp")
        print(dp)
        p1=request.user
        print(p1.username)
        print(p1.id)
        t=p1.username
        if (usernames == ""):
            print("nikhil")
            u = User.objects.get(username=p1.username)
            r=Profile(user=u,usernames=t,profilepic=dp)
            r.save()
            SignUp.objects.filter(username=p1.username).update(profilepic=dp)
        else:
            print("chutiya")
            SignUp.objects.filter(username=p1.username).update(profilepic=dp)
            Profile.objects.filter(usernames=p1.username).update(usernames=usernames,profilepic=dp)
        return render(request,"profile.html",{'pics':pics,"id":id})
    return render(request,"profile.html",{'pics':pics,"id":id})

def change_password(request):
    if request.method == 'POST':
        form = PasswordChangeForm(data=request.POST, user=request.user)
        if form.is_valid():
            print("form accepted")
            form.save()
            print(".fds")
            update_session_auth_hash(request, form.user)
            print(".fd")
            messages.success(request, 'Your password was successfully updated!')
            print(".f")
            return redirect('profile')
        else:
            print("erjkevnjfnejnv")
            messages.error(request, 'Please correct the error below.')
            return redirect('profile')
    else:
        form = PasswordChangeForm(user=request.user)
        # args = {'form': form}
        return render(request, 'change_password.html',{'form': form})

def privacy(request):
    pics=Slider.objects.all()
    id=0
    if request.method=="POST":
        usernames=request.POST.get("u")
        print(usernames)
        option=request.POST.get("opt")
        print("nikhil")
        print(option)
        p1=request.user
        if (usernames == ""):
            print("nikhil1")
            u = User.objects.get(username=p1.username)
            r=PrivateSetting(user=u,usernames=p1.username,private=option)
            r.save()
            SignUp.objects.filter(username=p1.username).update(private=option)
        else:
            print("chutiya")
            SignUp.objects.filter(username=p1.username).update(private=option)
            PrivateSetting.objects.filter(usernames=p1.username).update(private=option)
        return render(request,"profile.html",{'pics':pics,"id":id})
    return render(request,"profile.html",{'pics':pics,"id":id})

def search(request):
    id=6
    pics=Slider.objects.all()
    if request.method=="POST":
        usernames=request.POST.get("u")
        try:
            s=SignUp.objects.get(username=usernames)
            print(s.username)
            print(s.email)
            p=s.private
            print(p)
            return render(request,"profile.html",{'pics':pics,"id":id,'s':s,"p":p})
        except ObjectDoesNotExist:
            s=None
            msg="User Cannot Found"
            p="not"
            return render(request,"profile.html",{'pics':pics,"id":id,'s':s,"p":p,"msg":msg})
    return render(request,"profile.html",{'pics':pics,"id":id})

def file_upload(request):
    id=7
    pics=Slider.objects.all()
    if request.method=="POST":
        username=request.POST.get("u")
        title=request.POST.get("title")
        sem=request.POST.get("sem")
        sub=request.POST.get("sub")
        file= request.FILES.get("file")
        now = datetime.datetime.now()
        print(username,title,sem,sub,file,now)
        work=FileUpload(username=username,title=title,sem=sem,sub=sub,file=file,datetime=now)
        work.save()
        return render(request,"profile.html",{'pics':pics,"id":id})
    return render(request,"profile.html",{'pics':pics,"id":id})

def compile(request):
    id=8
    output="none"
    pics=Slider.objects.all()
    if request.method=="POST":        
        code=request.POST.get("code") 
        print(code)
        with open('compiler.cpp', 'w') as files:
            files.write(code)        
        cmd = 'g++ compiler.cpp -o compiler.exe'                                
        if os.system(cmd) == 0:                                     
            check_output(cmd, shell=True,stderr=STDOUT)            
            print("code compiled properly")
            cmd = '.\compiler.exe'
            newcheck = os.system(cmd)            
            output = check_output(cmd, shell=True,stderr=STDOUT)
            msg="code executed properly"                        
        else:
            try:
                check_output(cmd, shell=True,stderr=STDOUT)
            except CalledProcessError as e:
                output = e.output
                print("error was thrown")
                msg="error was thrown"
        return render(request,"tutor.html",{'pics':pics,"id":id,"output":output.decode('utf-8'),"code":code,"msg":msg})
        # print(compileoutput)        
    return render(request,"tutor.html",{'pics':pics,"id":id,})

def filehandlecompile(request):
    id=7
    output="none"
    pics=Slider.objects.all()
    if request.method=="POST":
        out=""
        s=int(request.POST.get("a"))
        e=request.POST.get("elements")
        c=[]
        c.append(s)
        data=list(map(int,e.split()))
        print(data)
        for i in data:
           c.append(i)
        print(c)
        np.savetxt('array.csv', [c], delimiter=',', fmt='%d')
        cmd = 'g++ nick.cpp -o dsnick.exe'
        os.system(cmd)
        print("code compiled properly")
        cmd = '.\dsnick.exe'
        os.system(cmd)
        print("code executed properly")
        f = open('ex.txt', 'r')
        out = f.read()
        print (out)
        f.close()
        return render(request,"tutor.html",{'pics':pics,"id":id,"out":out})
    return render(request,"tutor.html",{'pics':pics,"id":id,})