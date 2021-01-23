# Generated by Django 3.0.5 on 2020-05-15 16:32

from django.db import migrations, models


class Migration(migrations.Migration):

    dependencies = [
        ('nikhil', '0001_initial'),
    ]

    operations = [
        migrations.CreateModel(
            name='FileUpload',
            fields=[
                ('id', models.AutoField(auto_created=True, primary_key=True, serialize=False, verbose_name='ID')),
                ('username', models.CharField(max_length=50)),
                ('title', models.CharField(max_length=50)),
                ('sem', models.CharField(max_length=50)),
                ('sub', models.CharField(max_length=50)),
                ('file', models.FileField(upload_to='notes/')),
                ('datetime', models.CharField(max_length=50)),
            ],
        ),
    ]
