#encoding=utf-8

#将标注的txt文件转换为xml文件输出

import xml.dom.minidom as Dom
import sys,os



if __name__ == "__main__":
	textFile = open(sys.argv[1])
	doc = Dom.Document()
	root_node = doc.createElement("dataset")
	doc.appendChild(root_node)
	frameNo = -1
	frame_node = doc.createElement("frame")
	objlist_node = doc.createElement("objectlist")

	for line in textFile:

		line = line.strip()
		parts = line.split(" ")

		if int(parts[0]) == frameNo:
			obj_node = doc.createElement("object")
			obj_node.setAttribute("id",parts[1])
			box_node = doc.createElement("box")
			box_node.setAttribute("h",parts[5])
			box_node.setAttribute("w",parts[4])
			box_node.setAttribute("xc",parts[2])
			box_node.setAttribute("yc",parts[3])
			obj_node.appendChild(box_node)
			objlist_node.appendChild(obj_node)
		else:
			if frameNo == -1:
				frameNo = int(parts[0])
				frame_node.setAttribute("number",parts[0])
				
				obj_node = doc.createElement("object")
				obj_node.setAttribute("id",parts[1])
				box_node = doc.createElement("box")
				box_node.setAttribute("h",parts[5])
				box_node.setAttribute("w",parts[4])
				box_node.setAttribute("xc",parts[2])
				box_node.setAttribute("yc",parts[3])
				obj_node.appendChild(box_node)
				objlist_node.appendChild(obj_node)
			else:
				frame_node.appendChild(objlist_node)
				root_node.appendChild(frame_node)
				frameNo = int(parts[0])
				frame_node = doc.createElement("frame")
				frame_node.setAttribute("number",parts[0])
				obj_node = doc.createElement("object")
				obj_node.setAttribute("id",parts[1])
				box_node = doc.createElement("box")
				box_node.setAttribute("h",parts[5])
				box_node.setAttribute("w",parts[4])
				box_node.setAttribute("xc",parts[2])
				box_node.setAttribute("yc",parts[3])
				obj_node.appendChild(box_node)
				objlist_node = doc.createElement("objectlist")
				objlist_node.appendChild(obj_node)

	fxml = open("seq0108-gt.xml","w")
	fxml.write(doc.toprettyxml(indent="\t",newl = "\n",encoding = "utf-8"))
	fxml.close()
	textFile.close() 

