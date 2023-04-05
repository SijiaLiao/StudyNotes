### Github使用指南

##### clone项目

* github code 复制git@github.com:murufeng/CVPR_2021_Papers.git
* 文件夹内右键git bash here
* 黑框框内输入命令 git clone + git@github.com:murufeng/CVPR_2021_Papers.git

##### 上传项目

* 在github创建一个仓库
* 在本地文件夹的用hit bash here打开终端将项目clone下来，此时只有.git文件
* 将待上传的文件/文件夹复制到此文件中，与.git并列
* 右键再打开终端，输入命令 git add -A , 用于提交所有变化到暂存区
* 再输入用于将暂存区内容添加到本地仓库中的命令， git commit -m "first commit"
* 最后，输入 git push -u origin main , 将本地库中的内容发送到远程库中