##简介
这里主要有四个module，每个目录都是一个module，
##UsageEnvironment
```UsageEnvironment```这个是live555提供的最基本的运行环境的接口，其实只有两个关键类和一些没必要的接口罢了。
主要接口是```UsageEnvironment```。 这个是保存必要的运行环境的，```TaskScheduler```这个很好理解，就是维护任务的一个控制总类。
其他的就是两个Until类接口罢了，看名字就可以理解

##BasicUsageEnvironment
这是UsageEnvironment接口的实现，也就是live555的运行环境的一个实现。这个就需要以后详细介绍

##groupsock
主要是关于网络的，

##liveMedia
这才是关于rtsp和视频解码的核心部分，这里我们以后慢慢分析一下。
