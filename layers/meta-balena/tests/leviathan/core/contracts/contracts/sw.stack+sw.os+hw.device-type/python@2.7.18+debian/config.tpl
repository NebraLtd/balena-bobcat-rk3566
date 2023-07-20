# https://github.com/docker-library/python/issues/147
ENV PYTHONIOENCODING UTF-8

# set PYTHONPATH to point to dist-packages
ENV PYTHONPATH /usr/lib/python2.7/dist-packages:/usr/lib/python2.7/site-packages:$PYTHONPATH

RUN [ ! -d /.balena/messages ] && mkdir -p /.balena/messages; echo 'As of January 1st, 2020, Python 2 was end-of-life, we will change the latest tag for Balenalib Python base image to Python 3.x and drop support for Python 2 soon. So after 1st July, 2020, all the balenalib Python latest tag will point to the latest Python 3 version and no changes, or fixes will be made to balenalib Python 2 base image. If you are using Python 2 for your application, please upgrade to Python 3 before 1st July.' > /.balena/messages/python-deprecation-warning
