from django.contrib import admin
from .models import SignUp,Faculty,Slider,achieve,alumni,Library_vlink,Library_pdf,newsletter,Feedback,homepics,UserProfile,Profile,PrivateSetting
from .models import FileUpload,TutorContent
# Register your models here.
admin.site.register(SignUp)
admin.site.register(Faculty)
admin.site.register(Slider)
admin.site.register(achieve)
admin.site.register(alumni)
admin.site.register(Library_pdf)
admin.site.register(Library_vlink)
admin.site.register(newsletter)
admin.site.register(Feedback)
admin.site.register(homepics)
admin.site.register(UserProfile)
admin.site.register(Profile)
admin.site.register(PrivateSetting)
admin.site.register(FileUpload)
admin.site.register(TutorContent)


