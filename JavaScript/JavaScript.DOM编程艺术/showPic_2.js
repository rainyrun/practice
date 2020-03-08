//文档加载后，启动JS脚本
addLoadEvent(prepareGallery);
//启动函数
function prepareGallery(){
	//检查点
	if(!document.getElementsByTagName || !document.getElementById)
		return false;
	if(!document.getElementById("imagegallery"))
		return false;
	//获取表格
	var gallery = document.getElementById("imagegallery");
	//获得表格的列表项
	var links = gallery.getElementsByTagName("a");
	//遍历列表项，给个a元素加上onclick属性
	for (var i = links.length - 1; i >= 0; i--) {
		links[i].onclick = function(){
			return !showPic(this);//showPic(links[i])不起作用，alert(links[i]);显示undefined
		}
		// links.[i].onkeypress = links[i].onclick;
	}
}

//修改预览区显示点图片
function showPic(whichpic){	
	if(!document.getElementById("placeHolder"))
		return false;
	//获得图片链接地址、title属性
	var source = whichpic.getAttribute("href");
	//获取预览区域的元素
	var placeHolder = document.getElementById("placeHolder");
	//修改预览区域的展示图片
	placeHolder.setAttribute("src", source);

	if(document.getElementById("description")){
		var text = whichpic.getAttribute("title");
		//获取文字描述元素
		var description = document.getElementById("description");
		//修改文字区域的内容
		description.firstChild.nodeValue = text;
	}
	return true;
}

function addLoadEvent(func){
	var oldonload = window.onload;
	if(typeof window.onload != "function"){
		window.onload = func;
	}else{
		window.onload = function(){
			oldonload();
			func();
		}
	}
}