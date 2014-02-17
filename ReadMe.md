Opencv 视频标注工具，支持avi格式的视频标注，将视频中的物体编号标注出来
可以用于视频中目标跟踪的ground truth标注。

A label tool for video.Now only support the avi format video.
One can use this for labeling the ground truth of the video for object tracking

软件使用方法：
1.点击浏览打开视频文件，或者在地址栏输入具体的文件地址后点击打开视频/图像按钮
	输入的文件必须为无压缩的avi格式视频
2.如果需要设置标注数据的存储位置，直接修改标注数据存储位置的地址栏内容即可，默认放在视频文件相同的文件夹内，文件名称为  视频文件名称.txt
3.设置完成之后，点击开始标注便可以开始标注。注意，输入的label必须为数字。
4.在完成标注之后，必须点击完成标注按钮，否则可能会导致最后一帧的标注数据不能保存。

5.标注数据格式为：帧号 目标id 目标左上角x坐标 目标左上角y坐标 目标宽度 目标高度