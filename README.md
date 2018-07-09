# Live555-cmake
这是用于Android studio一个live555工程，编译脚本是gradle和cmake
## 使用
这里需要把视频或音频文件放到sd卡根目录。然后运行软件，通过logcat找到播放地址。

## TODO
因为这个cmake只是为了一直Android studio，cmake脚本写的不太好，不过讲道理应该直接可以通过cmake Gui处理，然后用vs打开，不过最终事与愿违，不知道为什么编译后报错。这里如果真的需要移植vs。
如果真的需要移植vs。其实完全可以通过比较简单的步骤实现这里就不在详细介绍
以后应该吧cmake调整一下，让他兼容性更好。
## 移植
这里修改了少部分代码，主要是
```groupsockerhelper.cpp```
