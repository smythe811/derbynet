Personal working copy of derbynet for testing local Linux builds for shared hosting environments. 

1. clone this repo
2. install apache ant 
3. from derbynet repo build with apache ant
4. copy website folder to your shared webserver www-root/derbynet
5. create derbynet/local and chmod 777 derbynet/local
6. copy template/default-file-path.inc to wwwroot/local/ and modify for you account path
7. open yourwebsite/derbynet
8. enjoy

TODO items:
1. update timer for json links or roleback to v6.0 branch for testing
2. check build.xml line 363 to confirm this won't interfere with automated builds. 

---

# Please visit the project web site at [http://jeffpiazza.github.io/derbynet](http://jeffpiazza.github.io/derbynet).

![icon](https://raw.githubusercontent.com/jeffpiazza/derbynet/master/website/img/derbynet-300.png)
