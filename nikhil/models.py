from django.db import models
from django.contrib.auth.models import User
from django.db.models.signals import *
from django.db.models.signals import post_save
# Create your models here.
class SignUp(models.Model):
    username=models.CharField(max_length=100)
    password=models.CharField(max_length=50)
    email=models.EmailField(max_length=254)
    first_name=models.CharField(max_length=50)
    last_name=models.CharField(max_length=50)
    profilepic=models.ImageField()
    phoneno=models.CharField(max_length=100)
    privateemail=models.EmailField(max_length=254)
    description=models.CharField(max_length=250)
    year=models.CharField(max_length=50)
    batch=models.CharField(max_length=50)
    address=models.CharField(max_length=200)
    skillset=models.CharField(max_length=300)
    github=models.URLField(max_length=200)
    hackerrank=models.URLField(max_length=200)
    codechef=models.URLField(max_length=200)
    private=models.CharField(max_length=20,default='no')
    
class Faculty(models.Model):
    Faculty_Name=models.CharField(max_length=100)
    Faculty_Post=models.CharField(max_length=100)
    Faculty_Image=models.ImageField()
    Faculty_Interest=models.CharField(max_length=200)
    Faculty_Phone=models.CharField(max_length=100)
    Faculty_Email=models.CharField(max_length=100)
    Faculty_Type=models.CharField(max_length=100)
    Faculty_Url = models.URLField(max_length=200)

class Slider(models.Model):
    pic=models.ImageField()
    index=models.IntegerField()

class achieve(models.Model):
    year=models.IntegerField()    
    info=models.CharField(max_length=300)


class alumni(models.Model):
    alumni_image=models.ImageField()
    alumni_name=models.CharField(max_length=100)
    alumni_batch=models.CharField(max_length=100)
    alumni_currentposition=models.CharField(max_length=200)
    alumni_details=models.CharField(max_length=400)

class Library_pdf(models.Model):
    pdf_type=models.CharField(max_length=100)
    pdf_subject=models.CharField(max_length=200)
    pdf_name=models.CharField(max_length=200)
    pdf_doc=models.FileField(upload_to='doc/')

class Library_vlink(models.Model):
    
    vlink_topic=models.CharField(max_length=200)
    vlink_url=models.URLField(max_length=200)

class newsletter(models.Model):
    email=models.EmailField(max_length=254)

class Feedback(models.Model):
    name=models.CharField(max_length=100)
    email=models.EmailField(max_length=254)
    subject=models.CharField(max_length=200)
    msg=models.CharField(max_length=500)

class homepics(models.Model):
    photos=models.ImageField()
    pictitle=models.CharField(max_length=100)
    picinfo=models.CharField(max_length=200)
    
class UserProfile(models.Model):
    user=models.OneToOneField(User,on_delete=models.CASCADE)
    usernames=models.CharField(max_length=50)
    phoneno=models.CharField(max_length=100)
    privateemail=models.EmailField(max_length=254)
    description=models.CharField(max_length=250)
    year=models.CharField(max_length=50)
    batch=models.CharField(max_length=50)
    address=models.CharField(max_length=200)
    skillset=models.CharField(max_length=300)
    github=models.URLField(max_length=200)
    hackerrank=models.URLField(max_length=200)
    codechef=models.URLField(max_length=200)
    def __str__(self):  # __str__
        return (self.user.username)
#def create_profile(sender, **kwargs):
#   if kwargs ['created']:
#        user = kwargs["instance"]
#        reg=UserProfile(user=user,usernames=user.username,year="none",batch="none",privateemail="none",phoneno="none",address="none",description="none",skillset="none",github="none",hackerrank="none",codechef="none")
#        reg.save()
#        user_profile= UserProfile.objects.create(user=kwargs['instance'])
#post_save.connect(create_profile, sender=User, dispatch_uid="users-profilecreation-signal")
class Profile(models.Model):
    user=models.OneToOneField(User,on_delete=models.CASCADE)
    usernames=models.CharField(max_length=50)
    profilepic=models.ImageField(upload_to='profile_image' , blank=True)
    def __str__(self):  # __str__
        return (self.user.username)

class PrivateSetting(models.Model):
    user=models.OneToOneField(User,on_delete=models.CASCADE)
    usernames=models.CharField(max_length=50)
    private=models.CharField(max_length=20)
    def __str__(self):  # __str__
        return (self.user.username)
 
class FileUpload(models.Model):
    username=models.CharField(max_length=50)
    title=models.CharField(max_length=50)
    sem=models.CharField(max_length=50)
    sub=models.CharField(max_length=50)
    file=models.FileField(upload_to='notes/')
    datetime=models.CharField(max_length=50)

class TutorContent(models.Model):
    topic_title=models.CharField(max_length=50)
    topic_name=models.CharField(max_length=50)
    topic_details=models.CharField(max_length=1000)
    topic_image=models.ImageField(upload_to='tutor' , blank=True)
    topic_cpp=models.FileField(upload_to='tutorcpp/')