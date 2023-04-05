### Github使用指南

##### clone项目

* github code 复制git@github.com:murufeng/CVPR_2021_Papers.git
* 文件夹内右键git bash here
* 黑框框内输入命令 git clone + git@github.com:murufeng/CVPR_2021_Papers.git

##### 上传项目

* 在github创建一个仓库
* 在本地文件夹的用hit bash here打开终端将项目clone下来，此时只有.git文件
* 将待上传的文件/文件夹复制到此文件中，与.git并列
* 在.git文件页面，右键再打开终端，输入命令 git add -A , 用于提交所有变化到**暂存区**
* 再输入用于将暂存区内容添加到**本地仓库**中的命令， git commit -m "first commit"
* 最后，输入 git push -u origin main , 将本地库中的内容发送到**远程库**中

##### 修改项目

* 修改项目前，先从远程库中克隆最新版本的项目到本地
* 如果在本地没有该项目的文件，则用git clone git@github.com:SijiaLiao/StudyNotes.git 将项目克隆下来
* 如果本地已有文件夹（本地仓库），在本地仓库.git页面，右键打开终端 输入命令 git pull,将项目拉取下来
* 在本地仓库中添加修改了的内容，即在.git页面添加/替换/删除文件
* 再暂存-本地仓库-远程库命令，将项目送上去
  * git add -A
  * git commit -m "注释"
  * git push -u origin main