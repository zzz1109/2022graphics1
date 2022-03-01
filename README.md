# 2022graphics1
## week01 
第一個OpenGL程式



0. CodeBlocks 17.12 mingw裝好

1. File-New-Project, 選OpenGL專案

2.在[點點點]的目錄中, 選「桌面」,Projectsje nir 01_OPENGL




3.下一步下一步,完成後,Build&Run

4.可以看到彩色旋轉的三角形






GLUT
1. Moodle下載 freeglut...zip

2.解壓縮桌面freeglut目錄

3.桌面freeglut的lib裡面有libfreeglut.a

把它複製,改成libglut32.a

才能讓我們的CodeBlocks的GLUT專案連結使用

4.CodeBlocks:File-New-Project,選GLUT專案

5.取名week01_GLUT

6.設定GLUT目錄 C:\Users\Administrator\Desktop\freeglut

7.Build&Run, 可看到6個紅色的東西在轉動

 




GitHub 備份程式
0. 登入GitHub.com

1.new repo 新增專案倉庫

1.1. 取名 2022graphics或2022graphics1

1.2.Public,Add README,

Add.gitignore用C++

1.3.綠色確認

2.利用Git指令

2.1.安裝Git for Windows

3.開啟 Git Bash

3.1. cd desktop 進入桌面

3.2. git clone https://網址

3.3. cd 2022graphics1

3.4. 把我們的2個程式目錄,放到2022graphics1

3.5. git status 看狀態(紅色2個目錄)

3.6. git add . 把它加進去

3.7. git status 再看狀態(變綠色)



4. 要推送上雲端

4.1. 要先有 commit 的動作, 第一次使用時,需



git config --global user.email "jsyeh@mail.mcu.edu.tw"

git config --global user.name "jsyeh"



git commit -m "訊息"



4.2. git push 推送上雲端

(Chrome 要登入才行)

## week02
step01-1

 1.下載範例 jsyeh.org/3dcg10

data.zip windows.zip glut32.dll

2.windows.zip =解壓=> 下載\windows\Shapes.exe

data.zip =解壓=> 下載\windows\data\模型 

glut32.dll =複製=> 下載\windows\glut32.dll

3.跑 Shapes.exe看範例,試試看





step01-2
1. 上周的安裝 Git for Windows

2. 上周的Git Bash: cd desktop,git clone 我的網址

3. 上周的安裝 freeglut 改檔名 lib\libglut32.a

4.  在CodeBlocks File-Open week01_GLUT專案,執行
