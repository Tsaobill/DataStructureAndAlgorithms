# 本地库初始化

## 1.创建本地库

git init

生成的 .git 目录是存放本地库相关的子目录和文件，不要修改和删除





## 2.设置签名

1.形式：

用户名：bill

Email地址：hi @ abc.com

2.作用：

用于区分不同开发人员身份 用户名和账户不必有关系

3.辨析：

这里设置的签名和登录远程库的账户密码没有任何关系

### 4.命令：

#### 4.1项目级别/仓库级别

git config

这里的签名只在该项目仓库中有效

例：

git config user.name tom_pro

git config user.email goodMorning_pro@ bill.com

#### 4.2系统用户级别

git config --global

登录当前操作系统的用户范围内都有效，

例：

git config --global user.name tom_glb

git config --global user.email goodMorning_glb@ bill.com

备注：没有设置项目级别默认使用系统级别的，二者都有，就近原则优先使用项目级别签名

二者至少有一个。

项目级别签名信息保存在 .git/config文件中 

系统用户级别用户信息保存在当前系统用户根目录中的 .gitconfig文件中



git status 命令：查看git状态

![1540645639572](C:\Users\bill\AppData\Roaming\Typora\typora-user-images\1540645639572.png)



当用文件修改或新增进之后 状态改变

![1540645804127](C:\Users\bill\AppData\Roaming\Typora\typora-user-images\1540645804127.png)



 说明新的文件没有添加到暂存区，用git add + 文件名 将其 添加到暂存区

保存LF被替换成 CRLF，但是在工作区仍然是LF



## git 修改默认编辑器 

### 1.改为vim

打开.git/config文件，在core中添加 editor=vim即可。

或者运行命令 `git config –global core.editor vim` 修改更加方便。

### 2.修改为其他编辑器

Git Bash 中输入以下命令即可成功：

```Git
git config --global core.editor "'D:\Notepad++\notepad++.exe' -multiInst -notabbar -nosession -noPlugin '$*'"
```

注：上面的 目录为编辑器的安装位置，按实际情况填写。





### 工作区和暂存区之间的操作

#### 1.从工作区提交到暂存区：

 `git add <file> `  1.添加新文件。2.添加修改后的文件到暂存区

#### 2.从暂存区移除文件，

 `git rm --cached <file>`。注：这并不会删除工作区的文件

`git reset HEAD <file>`  取消 将修改后的文件添加到暂存区。

### 暂存区和本地仓库之间的操作

#### 从暂存区提交的本地库：

 `git commit <file>` ，然后会自动打开默认编辑器 添加要备注的提交信息然后保存并退出即可

`git commit -m "提交信息" <file>`  加上-m 参数 后面在 引号中写要备注的信息 就可以直接提交到本地仓库

# 操作流程

![1540648486670](C:\Users\bill\AppData\Roaming\Typora\typora-user-images\1540648486670.png)



#### `git log` 命令	查看历史记录	

`git log --pretty=oneline`

每次记录一行显示

`git log --oneling`

更简洁，oneline参数只显示部分哈希值 而且只显示比当前版本更早的记录

`git reflog`

帮助恢复版本，显示移动 HEAD到目标版本需要的步数



## 前进后退历史版本 

#### 1、基于索引值操作【推荐】

使用 reflog 显示记录记录对照历史信息

然后 git reset --hard [哈希值] 到想要的版本的哈希值，不用考虑是版本前进还是后退

#### 2、使用^符号

只能版本往后 不能往前

 使用命令：`git reset --hard HEAD^`   往前移动版本，一个异或符号移动一个版本

#### 3、使用~符号

使用命令：`git reset --hard HEAD~n`  后退几步 n就是几



### 命令 hard、soft和mixed对比



--soft 参数仅仅在本地库移动HEAD指针

![1540650886758](C:\Users\bill\AppData\Roaming\Typora\typora-user-images\1540650886758.png)

--mixed 移动本地库HEAD指针，还会重置暂存区

![1540650918132](C:\Users\bill\AppData\Roaming\Typora\typora-user-images\1540650918132.png)

--hard 移动本地库HEAD指针，重置暂存区，重置工作区

![1540650982719](C:\Users\bill\AppData\Roaming\Typora\typora-user-images\1540650982719.png)

注：以绿线为基准，三个参数的区别示意。

### 永久删除文件的找回

1.删除文件

2.将删除文件记录提交到暂存区

3.删除文件记录提交到本地库

4.由于git的特殊属性，只会增加信息，不会修改或者删除信息。我们可以根据历史记录

将工作区的状态用git reset配合--hard参数加哈希值改到删除前的状态借此来恢复已删除文件

### 添加到暂存区的删除文件找回

执行了删除并提交到暂存区了 ，没有提交到本地库

这时候 直接 git reset --hard HEAD就可以了



### 比较文件

`git diff <file>` ：不加参数默认比较工作区和暂存区之间的差异

加上HEAD参数：比较工作区和本地库之间的差异

`git diff HEAD^ <file>` 和本地库中某一历史版本的差异

不指定文件名 比较所有文件的差异；

## Git 分支概念

![1540699748677](C:\Users\bill\AppData\Roaming\Typora\typora-user-images\1540699748677.png)

在分支中开发失败，直接删除即可，不会互相影响。 

开发成功，选择 和master分支合并，

![1540702759853](C:\Users\bill\AppData\Roaming\Typora\typora-user-images\1540702759853.png)

![1540702888083](C:\Users\bill\AppData\Roaming\Typora\typora-user-images\1540702888083.png)



### 分支好处

1.同时并行推进多个功能模块的开发，提高开发效率

2.各个分支开发过程相互独立，一个失败删除即可，不会影响到其他分支

### 分支操作

##### 1.创建分支 `git branch [name]` 

##### 2.查看分支 `git branch -v`

##### 3.切换分支 `git checkout [name]`

##### 4.合并分支 `git merge`

        1. 切换到接受修改的分支上（想要加新内容的分支 例如：master
        2. 执行`git merge [另一个分支名]` 新内容的分支   例如 ：hot_fix

##### 5.解决冲突 `git branch -v`

   1.进入文件，删除git自动添加的符合，修改文件到想要的状态，保存并退出。

2. git add [文件名]

   3.git commit -m “日志信息” ，然后后面不能带文件名。





# GitHub

##### 步骤：

1.创建远程库 （在GitHub上创建远程库）

2.在本地创建远程库别名 ：

​     1）`git remote -v ` 查看远程操作列表

​     2）`git remote add [别名] [地址]` 给地址添加别名

3.推送操作

  `git push  [别名] [分支名]` 完成推送，到GitHub上对应仓库即可看

4.克隆操作

   1）新建一个目录。

   2）执行命令：` git clone [远程库地址]` 完成克隆操作

   3）clone命令完成三件事：

​          1.完整的把远程库克隆到本地

​          2.创建远程库别名（相当于 git remote add 【别名】

​          3.初始化本地库（相当于git init 生成.git文件夹

克隆后修改文件 提交到本地库  

5.加入团队（不然无法推送到远程）

  远程库中 点击settings ---> 点击collaborators --->输入完整名称或者邮件地址    加入团队后 可以按照第三步完成推送。





## pull操作

pull = fetch + merge

#### 1.fetch

` git fetch [远程地址别名] [分支名]` 

从远程库内容抓起下来  并不会改变本地文件

   抓起下来的文件 在checkout  [别名]/[分支名] 下查看对应文件

#### 2.merge

` git merge [远程地址别名/分支名]` 

将远程库下载下来的文件 和 本地的分支合并 



### 解决冲突

在没有更新到远程库的最新版本之后是不能push的（即 要求是基于远程库的最新版做的修改才能push）必须先拉取。

因此 先pull 然后解决冲突 完成merge。

在此之后就正常的提交到本地库  再 push到远程库。



注： 注意区别 本地库分支之间的冲突和 远程库版本非最新引起的冲突直接的差别





## 跨团队协作操作演示

### fork + pull request 操作 

fork  新建 （复制）自己的远程库 然后clone到本地。修改 ，提交 

发起pull request操作 等待审核 ，完成 审核后 进行merge 







