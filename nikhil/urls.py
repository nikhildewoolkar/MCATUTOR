from django.urls import path
from . import views

urlpatterns = [
    #path('',views.home),
    #path('sorting/',views.algo),
    #path('ssort/',views.ssort),
    path("",views.home,name="home"),
    path("home/",views.home,name="home"),
    path("faculties/",views.faculties,name="faculties"),
    path("contact/",views.contact,name="contact"),
    path("library/",views.library,name="library"),
    path("login/",views.login,name="login"),
    path("signup/",views.signup,name="signup"),
    path("portal/",views.portal,name="portal"),
    path("tutor/",views.tutor,name="tutor"),
    path("students/",views.students,name="students"),
    path("logout/",views.logout,name="logout"),
    path("news/",views.news,name="news"),
    path("fb/",views.fb,name="fb"),
    path("profile/",views.profile,name="profile"),
    path("editprofile/",views.editprofile,name="editprofile"),
    path("ProfilePic/",views.ProfilePic,name="ProfilePic"),
    path("change_password/",views.change_password,name="change_password"),
    path("privacy/",views.privacy,name="privacy"),
    path("search/",views.search,name="search"),
    path("compile/",views.compile,name="compile"),
    path("file_upload/",views.file_upload,name="file_upload"),
    path("filehandlecompile/",views.filehandlecompile,name="filehandlecompile"),
    #path('',views.bsort),
    
]